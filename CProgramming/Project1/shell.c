/*
 * shell.c
 * Date: 2/9/15
 * Course: CSC3320
 * Description: This file implements a simple Unix shell.
 */
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <errno.h>
#include <string.h>
#include <stdbool.h>

/* Added by Alex */
#include <sys/types.h>
#include <sys/wait.h>


/* Our libraries. */
#include "history.h"
#include "joblist.h"

/* Define the maximum command length */
#define CMDLEN	1024
int COMMAND_STACK_SIZE = 1024; // Amount of commands that can be put into the stack 
int COMMAND_HISTORY_SIZE = 1000; // Amount of commands that will be stored in history

/* Prototypes */
void get_command(char *);
void sanitize_string(char *);
char* copyString(char s[]);
int build_argument_array(char***, int*, char*);
int handle_command(char** argv, int argc, char* cmd, history_hdl_t *cmd_history, joblist_hdl_t *jobs);

// Messages and Symbols
char error_message[] = "It looks like your command has an error, please try again.\n Error code: ";
char quit_one[] = "quit";
char quit_two[] = "exit";

int main(int argc, char **argv)
{
    int done = 0;    /* Determines if the user exites the shell. If done < 0, shell is exited */
    char cmd[CMDLEN];    /* Allocate space for a command. */
    history_hdl_t *cmd_history = history_create(COMMAND_HISTORY_SIZE);  /* Holds the command history. */
	joblist_hdl_t *jobs = joblist_create(); /* The joblist. */
    
    // your statements

	while(done == 0) {
		get_command(cmd);

		// Number of arguments
		int argc = -1;
		// Matrix for arguments
		char **argv;
		// Save the command
		char *cmd_holder = copyString(cmd);

		// Builds the argument array, fills out argc and argv.
		build_argument_array(&argv, &argc, cmd);

		// Make sure the user did not eneter a space.
		if(strcmp(cmd, "") != 0 && strcmp(cmd, " ") != 0) 
			// Handle the command and determine what needs to happen with the program.
			done = handle_command(argv, argc, cmd_holder, cmd_history, jobs);

		// If done is greater than 0, than we know an error was thrown with error id(done).
		if(done > 0) {
			printf("%s %d", error_message, done);
		}

		//joblist_print(jobs);
	}

	return 0;
}

/**
 * handle_command
 * Description: This function handles a command and creates processes
 * Returns: -1 if quitting, 0 if system command is executed, and > 0 if an error has occured (error type associated w/ value).
 * Got help from: https://www.section.io/engineering-education/fork-in-c-programming-language/
*/
int handle_command(char** argv, int argc, char* cmd, history_hdl_t *cmd_history, joblist_hdl_t *jobs) {	

	// Determine if quit statement
	if( strncasecmp(argv[0], quit_one, sizeof quit_one ) == 0 || strncasecmp(argv[0], quit_two, sizeof quit_two ) == 0 ) {
		return -1; // Return a negative number because we are quitting the loop.
	}

	// Determines if this task is a background process.
	bool backgroundProcess = (strcmp(argv[argc-1], "&") == 0) ? true : false;

	// Create a new process
	pid_t pid = fork();
	int status;

	if (pid < 0) { /* error occurred */
   		fprintf(stderr, "Fork Failed");
   		return 1;
   	}
	else if (pid == 0) { /* child process */

		// Add the process to the history
		history_add(cmd_history, cmd);

		/*
		Command Cases
		*/
		if(strcasecmp(argv[0], "history") == 0) { // History command
			//printf("%d", history_is_empty(cmd_history));
			if(history_is_empty(cmd_history) <= 0) 
			{ printf("The command history is empty.\n");} else {history_print(cmd_history);}
		} else if(strcasecmp(argv[0], "jobs") <= 0) { // Job command
			if(joblist_is_empty(jobs) == 0) 
			{ printf("The jobs list is empty.\n");} else {joblist_print(jobs);}
		}
		// Execute the given command.
		else {
			execvp(argv[0], argv);
		}
		
		exit(0);

		joblist_remove_job(jobs, pid);
    }
    else { /* parent process */
    	/* parent will wait for the child to complete */

		// Add the process to the job handler.
		joblist_add_job(jobs, pid);

		// If this is not a background process, we want to wait for the process to finish.
		if(!backgroundProcess) {
   	    	pid_t to_remove = wait(&status);
			joblist_remove_job(jobs, to_remove);
		} 
		// If this is a background process, we will wait for the process to complete, and then remove it from the job list
		// WITHOUT stopping the current process.
		// That is why I am using the option WUNTRACED (Return immediately if no child has exited. WUNTRACED: Also return if a child has stopped. Status for traced children which have stopped is provided even if this option is not specified.)
		else {
			pid_t to_remove = waitpid(pid, &status, WUNTRACED);
			joblist_remove_job(jobs, to_remove);
		}

		
    }


	return 0;
}

// Function to copy the string
// https://www.geeksforgeeks.org/different-ways-to-copy-a-string-in-c-c/
char* copyString(char s[])
{
    char* s2;
    s2 = (char*)malloc(20);
 
    strcpy(s2, s);
    return (char*)s2;
}
 


/**********************************************
 * 	Do NOT modify the code below.	      *
 **********************************************/

/*
 * get_command
 * Description: This function fills the array cmd with the
 * 		command run from the comamnd line. The
 * 		command line itself has no trailing spaces.
 */
void get_command(char *cmd)
{
	/* Zero the cmd buffer. */
	memset(cmd, 0, CMDLEN);

	/* Prompt for the command. */
	printf("msh> ");
	fgets(cmd, CMDLEN, stdin);

	/* Strip a trailing newline. */
	cmd[strlen(cmd) - 1] = '\0';

	sanitize_string(cmd);
}

/*
 * sanitize_string
 * Description: This function removes all the leading and trailing
 * 		spaces from a string.
 * Pre: cmd is not NULL
 * Post: The cmd pointed to is stripped of leading and trailing white space.
 */
void sanitize_string(char* cmd)
{
	int idx;		/* Use to track position in the string. */

	/* Strip all trailing white space. */
	for(idx = strlen(cmd) - 1; isspace(cmd[idx]) != 0 &&
	    idx >= 0; idx--)
		cmd[idx] = '\0';

	/* Strip leading white space. */
	while (isspace(cmd[0]) != 0)
		for (idx = 0; idx < strlen(cmd) - 1; idx++)
			cmd[idx] = cmd[idx + 1];
}

/*
 * build_argument_array
 * Description: This function takes a command an breaks it up into
 * 		an array of arguments. The last command is NULL.
 * Pre: cmd != NULL
 * Post: argc holds the number of arguments and argv holds the
 * 	 command line arguements themselves. The function returns
 * 	 ENOMEM on bad allocations and 0 on success.
 */
int build_argument_array(char***argv, int* argc, char* cmd)
{
	int idx;	/* The current location in cmd. */
	char *tok;	/* The current token. */

	assert(cmd != NULL);	/* Make sure the command is NOT NULL. */

	/*
	 * Determine the number of arguemtns by counting the number
 	 * of spaces.
 	 */
	*argc = 1;
	for (idx = 0; idx < strlen(cmd); idx++)
		if (cmd[idx] == ' ')
			(*argc)++;

	/*
 	 * Allocate the space for you argument array.
 	 */
	*argv = (char **)calloc(*argc + 1, sizeof (char *));

	/* Check to see if the allocation succeeded. */
	if (*argv == NULL)
		return ENOMEM;

	/* Set all strings to NULL. */
	for (idx = 0; idx < *argc + 1; idx++)
	    (*argv)[idx] = NULL;


	/*
	 * Walk through the command creating each necessary
 	 * command.
 	 */
	idx = 0;
	tok = strtok(cmd, " ");
	while(tok != NULL)
	{
		/* Copy the string into the argument array. */
		(*argv)[idx] = (char *)calloc(strlen(tok) + 1,  sizeof (char));
		strncpy((*argv)[idx], tok, strlen(tok));
 		idx++;

 		/* Continue tokenizing the same strings. */
		tok = strtok(NULL, " ");
	}

	return 0;
}

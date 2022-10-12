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

/* Our libraries. */
#include "history.h"
#include "joblist.h"

/* Define the maximum command length */
#define CMDLEN	1024

/* Prototypes */
void get_command(char *);
void sanitize_string(char *);
int build_argument_array(char***, int*, char*);
void handle_command(char** argv, int argc);

int main(int argc, char **argv)
{
    int done = 0;    /* Determines if the user exites the shell. If done < 0, shell is exited */
    char cmd[CMDLEN];    /* Allocate space for a command. */
    history_hdl_t *cmd_history;    /* Holds the command history. */
    joblist_hdl_t *jobs;    /* The joblist. */
    
    // your statements

	// Messages and Symbols
	char msg_header[] = "msh> ";
	//char space[] = "\n";
	char quit_one[] = "quit";
	char quit_two[] = "exit";
	char error_message[] = "It looks like your command has an error, please try again.";

	while(done >= 0) {
		get_command(cmd);


		// Number of arguments
		int argc;
		// Matrix for arguments
		char **argv;

		// Builds the argument array, fills out argc and argv
		build_argument_array(&argv, &argc, cmd);

		handle_command(argv, argc);

		// print cmd
   		//printf("%s\n", cmd);

		//printf("%d", strncasecmp("hello", "Hello", sizeof "Hello" ));

		// Get rid of the memory
		//free(cmd);
	}
    
    // Get rid of the memory
	//free(cmd);

	return 0;
}

/**
 * handle_command
 * Description: This function handles a command and creates processes
*/
void handle_command(char** argv, int argc) {
	for(int i = 0; i < argc; i++) {
		printf("%s ", argv[i]);
	}
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

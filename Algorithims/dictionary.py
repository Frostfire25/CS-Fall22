# Challenge Problem: Common Dictionary Algorithms
# Write the following standard data structure functions using Python. The input for each should be an array
# A (along with any other information you may need). Determine the (tight) Big-Oh of each of them based on
# n, the number of elements currently in the array. If you decide to do something beyond the trivial for each,
# justify in words why the Big-Oh is what you have claimed based on the construction of the data structure.
# • push and pop (treat it like a stack)
# • enqueue and dequeue (treat it like a queue)
# • removeDuplicates (turn it into a set)
# • insert (treat it as a binary search tree, assume its initial configuration is already a valid BST)

# M is the number to be pushed, A is the array
# Pushes element M to the front of array A.
# O(n)
def push( M, A ):
	N = [M]
	for i in range(len(A)):
		N[i+1] = A[i]
	A = N	

# A is the array
# Removes and returns the first element in the array
# O(n)
def pop( A ):
	F = A[0]
	N = []
	for i in range(len(A)):
		N[i] = A[i+1]
	A = N
	return F


# M is the element being queued, A is the array
# O(1)
def enqueue( M, A ):
	A[len(A)] = M

# A is the array
# O(n)
def dequeue( A ):
	return pop(A)
	
# A is the array
# Removes duplicate values in array A	
# O(n^2)
def removeDuplicates( A ):
	index = 0
	output = []
	for m in A:
		if m not in output:
			output[index] = m
		output += 1
	A = output		

# Inserts value val into Array A at position where the number fits
# A is a BST, basically it is sorted
# O(n)
def insert( A, val ):
	output = []
	insert = False
	for i in range(len(A)):
		# Make sure we have not already inserted
		# Make sure that we are not on the last element 
		if(not insert and not (i == len(A)) and val > A[i] and val < A[i + 1]):	
			output[i] = val
			insert = True
		# If we hit the end of the list, than add the element to the end
		elif(not insert and (i == len(A))):
			output[i] = val
			insert = True
		else:
			if(not insert):
				output[i] = A[i]
			else:
				output[i + 1] = A[i]
	A = output
	

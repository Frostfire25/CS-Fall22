import math

# Write a brute-force algorithm in Python to determine if the array of integers is in sorted order.
# Determine its running time and space requirements.

# Input: An array of numbers
# Output: A boolean determining if that array of numbers is sorted
# Running time for this algorithm is O(n)
def isSorted( A ):
    lV = A[0]
    for i in range( 1, len(A) ):
        if A[i] < lV:
            return False
        lV = A[i]    
    return True
    
#print(isSorted([1,2,3,4,5]))

# Develop a brute-force algorithm to compute the mean value of an array of integers. 
# What is its asymptotic running time?
# Input: An array of integers
# Output: An integer i which is the mean (average) of all of the numbers
# Running Time: O(n)
def mean( A ):
    total = 0
    for i in range( len(A) ):
        total += A[i]
    return total / len(A)

#print(mean([1,2,3,4,5]))

# Develop a brute-force algorithm to compute the median value of an array of integers. 
# What is its asymptotic running time?
# Input: An array of integers A
# Output: A median value
# Running Time: Constant time. Only a mathmatical operation is called whichs gets a index in A
def median( A ):
    return A[math.floor(len(A)/2)]

#print(median([1,31,3,214,14,12,12,3,4,232,1,7,12,34,1]))

# Develop a brute-force algorithm to compute the mode of an array of integers. 
# What is its asymptotic running time?
# Input: An array of integers A
# Output: The most frequent number in array A as an integer
# Running Time: I will be breaking down time running time of this algorithim
# 
def mode( A ):
    Dict = {}
    # Adds all the values to the dictionary
    for i in range(len(A)):
        val = A[i]
        # O(n) time complexity for the in operator, does a linear search
        if(val in Dict.keys()):
            Dict[val] = Dict[val] + 1
        else:
            Dict[val] = 1
        
    # Loop through the dictionary and find the highest values
    # Running Time: O(n), because at worst case there are no duplicates in A and len(Dict) == len(A) == n   
    key = 0
    val = 0
    for i in Dict.keys():
        if Dict[i] > val:
            key = i
            val = Dict[i]
    
    return key

#print(mode([1,21,312,31,231,1,1,32,3,1,1,7]))
#print(mode([9,9,9,9,9,9,9,9]))

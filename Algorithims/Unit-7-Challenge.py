import math

# Determine a brute force algorithm to find the two closest elements without altering the data in
# any way. What is the running time of your algorithm?
# Brute force solution to the distance problem
def Distance_Consecutive( Q ): 
    smallest_distance = 100
    A = Q.copy()
    A.sort()
    # Loop through each number
    for i in range(1, len(A) - 1):
        if(distance(A[i-1], A[i]) < smallest_distance):
            smallest_distance = distance(A[i-1], A[i])

    return smallest_distance
    
        
# Returns the distance of two numbers
def distance(x, y):
    return abs( x - y )

A = [1, 43, 32, 23, -5, 3, 99]

print(Distance_Consecutive(A))

# Given two strings, s1 and s2 of length n, create a Θ (n lg n) algorithm to determine if s1 and s2 are
# anagrams (contain the same characters).
def Anagram( s1, s2 ): 
    s1T = sorted(s1) # O(nln)
    s2T = sorted(s2) # O(nln)
    return s1T == s2T # O(n)

print(Anagram("hello", "olleh"))

# We want to use the Jarvis March Algorithm to solve this convex hull problem.


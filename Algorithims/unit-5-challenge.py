import math
import random

# Define constant array for both searches
ARRAY = []
for i in range(0,10):
    ARRAY.append(math.floor(random.random() * 1000000))

ARRAY.sort()
print(ARRAY)

# Implementation of the Binary Search algorithm
# Input: an array A and a value k.
# Output: If the array contains k.
# Big O: log(n), the k is not in A
# Big Omega: 1, k is A[len(a)/2] 
def BinarySearch( A, k ):
    if(len(A) == 1):
        return A[0] == k
    else:
        half = A[math.floor(len(A)/2)]
        if(k > half):
            return BinarySearch(A[math.floor(len(A)/2):], k)
        elif( k < half):
           return BinarySearch(A[:math.floor(len(A)/2)], k)
        else: 
            return True

# Implementation of an interpolation search
# Input an array A of sorted integers
# A value k to be searched for
# H and L are the bounds for searching array L, where H is the Highest Bound, and L is the lowest bound.
def InterpolationSearch( A, k, H, L ):
    
    # Base Case
    if(L < 0 or H >= len(A)):
        return False

    # Do point slope form substituted math
    x = math.floor(((k - A[L]) * (H - L))/(A[H] - A[L])) + L
    print(x)

    # Base case, if the estimated point is out of bounds
    if(x >= len(A) or x < 0):
         return False

    # Check found, if not then recurse on given bound from x
    if(A[x] < k):
        return InterpolationSearch(A, k, (x-1), L)
    elif(A[x] > k):
        return InterpolationSearch(A, k, H, (x+1))
    else:
        return True

#I = [1,2,3,4,5,6,7,8,9,10]
print(InterpolationSearch(ARRAY, ARRAY[2], len(ARRAY)-1, 0))
print(BinarySearch(ARRAY,ARRAY[2]))


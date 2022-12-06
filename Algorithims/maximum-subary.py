import math

A = [1, -2, 3, -7, 2, -1, 4, -1, -2] #[1, -2, 3, -7, 2]

# 1, 1 -2...
# -2, 3

# Input an array of integers A
# Output the subaray inside of a which has the maximum sub
def MaximumSubArray( A ):

    max_value = A[0]
    max_subarray = [A[0]]

    for i in range(0, len(A) + 1): # Time Complexity of n
        for q in range(i, len(A) + 1): # Geometric series, complexity of n-k
            cals = 0
            for j in range(i, q):
                cals += A[j]

            print(A[i:q])
            if(cals > max_value):
                max_value = cals
                max_subarray = A[i:q]    

    print(max_value)
    return max_subarray

print(MaximumSubArray(A))
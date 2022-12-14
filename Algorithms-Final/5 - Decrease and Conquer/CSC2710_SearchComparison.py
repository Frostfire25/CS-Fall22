import random
import math
import time

def BinarySearch( A, start, end, k ):
    m = math.floor((end + start) / 2)                   # Line 1
    if( start > end ):                                  # Line 2
        return None                                     # Line 3
    else:                                               # Line 4
        if( A[m] == k ):                                # Line 5
            return m                                    # Line 6
        elif( A[m] > k ):                               # Line 7
            return BinarySearch( A, start, m-1, k )     # Line 8
        else:                                           # Line 9
            return BinarySearch( A, m+1, end, k )       # Line 10



# Challenge Problem - Interpolation Search

def nearest_mid(input_list, lower_bound_index, upper_bound_index, search_value):
    return lower_bound_index + \
        (upper_bound_index - lower_bound_index) * \
        (search_value - input_list[lower_bound_index]) // \
        (input_list[upper_bound_index] - input_list[lower_bound_index])

def interpolation_search(A, k):

    size_of_list = len(A) - 1

    start = 0
    end = size_of_list

    while start < end:
        m = nearest_mid(A, start, end, k)

        if m > end or m < start:
            return None

        if A[m] == k:
            return m

        if k > A[m]:
            start = m + 1
        else:
            end = m - 1

    if start == end and A[start] is k:
        return start
    if start > end:
        return None


# Create the search list
searchValues = [ random.randrange(0,1000000) for x in range(500) ]
L = [ random.randrange(0,1000000) for x in range(10000) ]
L.sort()

start_time = time.perf_counter()
for i in searchValues:
  res2 = interpolation_search( L, i )
  if( not res2 is None ):
    print( "IS: ", res2 )
end_time = time.perf_counter()
print("Interpolation search took: ", end_time - start_time )

start_time = time.perf_counter()
for i in searchValues:
  res = BinarySearch( L, 0, len(L)-1, i )
  if( not res is None ):
    print( "BS: ", res )
end_time = time.perf_counter()
print("Binary search took: ", end_time - start_time )

  



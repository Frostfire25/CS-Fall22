
# Recursive method that prints all the pairs from an input array
# Input: array of numbers
# Output: Prints all pairs
def printing_pairs( arr ):
    # If we are on the last element, return
    if len(arr) == 1:
        return

    # Print this element as pairs with the other elements
    element = arr[0]
    for n in range(1, len(arr)):
        print("["+str(element)+","+str(arr[n])+"]")

    # Use slicing to recursivley remove the first element in r
    printing_pairs( arr[1:] )


# Initilize array and run method
arr = [3,4,1,6]
printing_pairs( arr )
    
# Input : An array of integers A
# Output : S >= 0
def Mystery ( A ):
    S = 0
    for i in range ( len( A ) ):
        S = ( i/( i+1 ) ) * S + ( 1/( i+1 ) ) * A[i]
    return S

m = Mystery([1,2,3])

print(m)

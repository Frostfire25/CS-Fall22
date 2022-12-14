# Input: A binary search tree stored as an array, and an element k to insert
# Output: The binary search tree with k inserted
def insert( T, k ):
    i = 1
    while( T[i] != None ):
        if( k < T[ i ] ):
            i = i * 2
        else:
            i = i * 2 + 1
    T[ i ] = k

# Input: A binary search tree stored as an array, and an element k to delete
# Output: The binary search tree with k removed
def delete( T, k ):
    i = 1
    while( T[ i ] != k ):
        if( k < T[ i ] ):
            i = i * 2
        else:
            i = i * 2 + 1
    # Replace the node with it's left child, all the way down to the leaves
    while( T[i] != None ):
        T[i] = T[i*2]
        i = i * 2


T = [ None for x in range(16) ]

insert( T, 5 )
insert( T, 3 )
insert( T, 2 )
insert( T, 6 )
insert( T, 10 )
insert( T, 8 )

print(T)

delete(T, 5)

print (T)

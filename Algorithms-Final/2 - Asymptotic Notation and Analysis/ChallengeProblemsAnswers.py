# 2710 Unit 2 Challenge Questions

# Input: A list L, and an element to push onto L k
# Output: The list L with k pushed
def StackPush( L, k ):
  L.append(k)

# Input: A list L
# Output: L without the last element
def StackPop( L ):
  L.pop( len(L) - 1 )

# Testing push and pop
L = [ 1, 2, 3, 4, 5, 6 ]
StackPush( L, 0 )
print( L )
StackPop( L )
print( L )














# Testing enqueue and dequeue

# Input: A list L and an element k to be enqueued
# Output: The list L has k enqueued
def Enqueue( L, k ):
  L.append(k)

# Input: A list L
# Output: The list L has the oldest element removed and returned
def Dequeue( L ):
  return L.pop( 0 )

Enqueue( L, 44 )
print(L)
Dequeue( L )
print(L)












# Making it a Set
# Input: A list L
# Output: L has a set is returned
def removeDuplicates( L ):
  i = 0
  while( i < len(L) ):
    if( L[i] in L[i+1:] ):
      L.remove( L[i] )
      i -= 1
    i += 1

L = [ 1, 4, 2, 5, 4, 3, 4, 2, 1, 3, 4, 4, 2, 3 ]
print( L )
removeDuplicates( L )
print( L )

















# Working with a BST
# Input: A BST L and an item to insert k
# Output: L contains k in the appropriate spot
def insert( L, k ):
  i = 1 # Have to start at 1 to avoid indexing issues
  while( not L[i] is None ):
    # Check to see if L[i] is empty
    if( k > L[i] ):
      i = i * 2 + 1
    else:
      i = i * 2
  L[i] = k



L = [ None for i in range( 200 ) ]
print( L )
insert( L, 5 )
insert( L, 2 )
insert( L, 2 )
insert( L, 5 )
insert( L, 4 )
insert( L, 6 )
insert( L, 1 )
insert( L, 8 )
insert( L, 4 )
insert( L, 9 )
insert( L, 7 )
insert( L, 7 )
print( L )


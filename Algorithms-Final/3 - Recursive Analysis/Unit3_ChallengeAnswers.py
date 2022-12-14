# Problem 3 - Printing Pairs:
# Input: A list L
# Output: All pairs within L printed to the screen
def printPairs( L ):
  if( len(L) == 1 ):
    return
  for i in range( 1, len(L) ):
    print( '[' + str(L[0]) + ',' + str(L[i]) + ']' ) 
  printPairs( L[1:] )

L = [ 4, 5, 3, 4 ]
printPairs(L)


# Problem 4 - Power Set
# Input: A set myset
# Output: A set of all of the subsets of myset
# https://stackoverflow.com/questions/41626379/python-power-set-of-a-list
def pset(myset):
  if not myset: # Empty list -> empty set
    return [set()]

  r = []
  for y in myset:
    sy = set((y,))
    for x in pset(myset - sy):
      if x not in r:
        r.extend([x, x|sy])
  return r

print(pset(set((1,2,3,4))))



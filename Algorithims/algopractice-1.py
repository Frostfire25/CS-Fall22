#Imports
import math

# Input : An array of integers A
# Output : The returned value is an integer
def Enigma ( A ):
    if( len( A ) == 1 ):
        return A[0]
    else :
        return Enigma ( A[ : math.floor ( len ( A )/2 ) ] ) * Enigma ( A[ math.floor (len ( A )/2 ) : ] )

print(Enigma([1.4,2.4,7.2]))

# Input : An array of integers A
# Output : S >= 0
def Mystery ( A ):
    S = 0
    for i in range ( len( A ) ):
        S = ( i/( i+1 ) ) * S + ( 1/( i+1 ) ) * A[i]
    return S
    
print(Mystery([1,3]))
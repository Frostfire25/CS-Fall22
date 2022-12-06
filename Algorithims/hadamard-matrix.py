import math
import numpy as np
import random
from array import *

def GenerateHadamardMatrix( k ):
    if( k == 1 ):
        return [ 1 ] # Return the single array Hamiltonian Matrix

    A = np.zeros((k,k)) # Initilize empty 2D array
    PopulateMatrix( A , k, 0, 0 ) # Call the firt populate matrix call
    return A

        
def PopulateMatrix( A, k, x, y ):
    if(k == 1):
        A[x][y] = random.choice([-1, 1])
    else:
        column = False
        for i in range(0, k):
            if(column):
                PopulateMatrix( A, k-1, x, y)
                column = False
            else:
                y = y + 1
                PopulateMatrix( A, k-1, x, y)
                column = True

print(GenerateHadamardMatrix(3))
            
    

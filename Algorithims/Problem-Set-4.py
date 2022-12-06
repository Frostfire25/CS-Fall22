import numpy as np

# Row
m = 8
# Column
n = 8
# Creating an empty matrix representing the picture
pictureMatrix = np.empty((m, n))
disruptiveMatrix = np.random.rand(m, n)

seems = []

# Input disruption matrix d
# Output lowest value of a seem 
def DisruptiveCalculation( d ):
    
    # Run the DCR over each seem
    for i in range(m):
        if(i > 0):
            seems.push( DCR(d, i, i-1) )
        if(i < (n-1)):
            seems.push( DCR(d, i, i + 1) )
        seems.push( DCR(d, i, 0) ) 

    return min(seems)    
        

# Recursive method to determine the seems and find their values
def DCR( d, row, column ):
    # Base case, we do not want rows or columns outside of bounds
    if(row >= m or column >= n or row < 0 or column < 0):
        return 0

    # Now we want to recurse for the seem
    return d[row][column] + DCR(d, row + 1, column - 1) + DCR(d, row + 1, column) + DCR(d, row + 1, column + 1)

print(DisruptiveCalculation( disruptiveMatrix ))

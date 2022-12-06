# Import necessary modules
from sklearn.neighbors import KNeighborsClassifier
from sklearn.model_selection import train_test_split
from sklearn.datasets import load_iris
import math as math
  
# Loading data
irisData = load_iris()
  
# Create feature and target arrays
X = irisData.data
y = irisData.target
  
# Split into training and test set
# We do this to develop models and establised polished datasets.
X_train, X_test, y_train, y_test = train_test_split(
             X, y, test_size = 0.2, random_state=42)
  
# Create the K Neighbors Classiffier object with a K-value of the sqrt(n)   
knn = KNeighborsClassifier(n_neighbors=math.sqrt(len(irisData.data)))
  
# Add our data to our K Neighbors Classiffier  
knn.fit(X_train, y_train)
  
# Predict on dataset which model has not seen before
print(knn.predict(X_test))
import torch
import numpy as np
from collections import Counter

# my_n_neighbors represents the number of nearest neighbors to consider.
# You can adjust this value as needed, e.g., setting n_neighbors=32 will consider the 32 closest neighbors for prediction. 
my_n_neighbors = 4


class KNNModel:
    def __init__(self, n_neighbors):
        self.n_neighbors = n_neighbors
        self.X_train = None
        self.y_train = None

    def load_data(self, file_name):
        images, labels = torch.load(file_name)
        images = [img.view(-1).numpy() for img in images]  
        return images, labels

    def fit(self, X_train, y_train):
        self.X_train = np.array(X_train)
        self.y_train = np.array(y_train)

    # TODO: modify only this function to implement KNN prediction. 
    # The returned predictions list will be used for scoring
    def predict(self, X_test):
        X_test = np.array(X_test)
        predictions = []
        
        for x in X_test:
            # distances
            distances = np.sqrt(np.sum((self.X_train - x) ** 2, axis=1))

            # n_neighbors
            nearest_indices = np.argsort(distances)[:self.n_neighbors]
            nearest_labels = self.y_train[nearest_indices]

            # predictions 
            most_common_label = Counter(nearest_labels).most_common(1)[0][0]
            predictions.append(most_common_label)

        return predictions

    def __call__(self,):
        pass
        
# Instructions: Complete only the class implementation. You may add print statements to test when using the "Run" button, 
# but only the class will be used for grading upon submission.

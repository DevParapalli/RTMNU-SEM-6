import numpy as np
import matplotlib.pyplot as plt
from sklearn.datasets import make_blobs

# Generate data
X, y, centers = make_blobs(n_samples=100, centers=2, n_features=2, random_state=1, return_centers=True)

# Get the bounding box
min_x, min_y = np.min(X, axis=0)
max_x, max_y = np.max(X, axis=0)

# Plot the data and the bounding box
plt.scatter(X[:, 0], X[:, 1], c=y)
plt.plot([min_x, min_x, max_x, max_x, min_x], [min_y, max_y, max_y, min_y, min_y], 'r-')
plt.show()
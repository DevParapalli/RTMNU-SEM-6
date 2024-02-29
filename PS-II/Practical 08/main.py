import pathlib as pl
import os
import pandas as pd
from sklearn.datasets import make_blobs
from sklearn.cluster import KMeans
import matplotlib.pyplot as plt

__RANDOM_STATE__ = 35
COLORS = ['red', 'green', 'blue']

script_dir = pl.Path(__file__).parent.absolute()
os.chdir(script_dir)


X, y_true = make_blobs(n_samples=300, centers=3, random_state=__RANDOM_STATE__)

plt.subplot(1, 2, 1)
plt.scatter(X[:, 0], X[:, 1], c=y_true, marker='o')
plt.title("Original Clusters")

three_means = KMeans(n_init='auto', n_clusters=3, random_state=__RANDOM_STATE__)

y_pred = three_means.fit_predict(X)

y_pred[y_pred == 1] = 4
y_pred[y_pred == 0] = 3
y_pred[y_pred == 2] = 0
y_pred[y_pred == 3] = 1
y_pred[y_pred == 4] = 2

plt.subplot(1, 2, 2)
plt.scatter(X[:, 0], X[:, 1], c=y_pred, marker='o')
plt.title("Predicted Clusters")
# for x, y, true, pred in zip(X[:, 0], X[:, 1], y_true, y_pred):
#     if true == pred:
#         plt.scatter(x, y, c=COLORS[pred], marker='o')
#     else:
#         plt.scatter(x, y, c='red', marker='x')

correct = (y_true == y_pred).sum()
incorrect = (y_true != y_pred).sum()
accuracy =  correct / len(y_true)
print(f"Correct: {correct} | Incorrect: {incorrect} | Accuracy: {accuracy}")
plt.show()
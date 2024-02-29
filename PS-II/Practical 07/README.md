# Practical 07: Classification Model

## Aim

a. Install relevant package for classification.
b. Choose classifier for classification problem.
c. Evaluate the performance of classifier.

## Theory

Classification is a supervised machine learning task that involves learning a mapping function from input feature vectors $X$ to a discrete set of class labels $Y$, where $X = {x_1, x_2, ..., x_n}$ and $Y = {y_1, y_2, ..., y_m}$. The goal is to build a classification model that can accurately predict the class label of a new, unseen input feature vector.

Formally, the classification problem can be defined as follows:

Given a training dataset $D = {(x_1, y_1), (x_2, y_2), ..., (x_n, y_n)}$ where $x_i$ is an input feature vector and $y_i$ is the corresponding class label, the objective is to learn a function $f: X \rightarrow Y$ such that $f(x) = y$ for any new input feature vector $x$.

To learn the function $f$, we typically use a machine learning algorithm that searches for the best set of model parameters $w$ given a loss function $L$. The loss function measures the difference between the predicted class label and the true class label.

During training, the algorithm iteratively adjusts the model parameters to minimize the loss function, effectively learning a mapping from the input features to the class labels. Once the model is trained, it can be used to make predictions on new, unseen data.

The performance of a classification model can be evaluated using various metrics, such as accuracy, precision, recall, and F1 score. These metrics provide a quantitative measure of the model's ability to accurately predict the class labels.

## Practical Files

- [main.py](./main.py)
- *[iris.csv](./iris.csv)

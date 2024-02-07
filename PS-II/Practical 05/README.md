# Practical 05 : Regression Model

## Aim

Import a data from web storage. Name the dataset and now do Logistic Regression to find out relation between variables that are affecting the admission of a student in a institute based on his or her GRE score, GPA obtained and rank of the student. Also check the model is fit or not. Require (foreign), require (MASS).

## Datasets Used

- <https://www.kaggle.com/datasets/mohansacharya/graduate-admissions/>

    Name: Graduate Admissions 2

    Columns: Serial No., GRE Score, TOEFL Score, University Rating, SOP, LOR, CGPA, Research, Chance of Admit

## References

- <https://www.kaggle.com/code/naishalthakkar/gre-dataset-analysis/input>


## Theory

Logistic regression is a statistical model commonly used in regression analysis, particularly for binary classification problems. It is a supervised learning model. In this model, the log-odds of an event are expressed as a linear combination of independent variables. The binary dependent variable takes on values "0" and "1," representing the absence or presence of an event. Independent variables can be either binary or continuous.

The logistic model employs the logistic function to convert log-odds to probabilities, ranging between 0 and 1. The logistic regression model is widely used for predicting the probability of an event occurring, such as a team winning or a patient being healthy. It has been a popular choice for binary regression since around 1970.

The logistic function is of the form

$$ p(x) = \frac{1}{1+e^{-(x-\mu)/s}} $$

where $p(x)$ is the probability of the event occurring, $x$ is the independent variable, $\mu$ is the location parameter (midpoint of curve, where $p(u) = 1/2$ ), and $s$ is the scale parameter.

## Practical Files Used

- [a.py](./a.py)
- @[a.png](./a.png)
- *[admissions-predict.csv](./admissions-predict.csv)

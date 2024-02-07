import pandas as pd
import numpy as np
import pathlib as pl
import os
import matplotlib.pyplot as plt
from sklearn.model_selection import train_test_split
from sklearn.linear_model import LinearRegression
from sklearn.metrics import mean_absolute_error,mean_squared_error,explained_variance_score,r2_score

script_dir = pl.Path(__file__).parent.absolute()
os.chdir(script_dir)

df = pd.read_csv('admissions-predict.csv')

df = df.drop(['Serial No.'], axis=1)
df.columns= df.columns.str.strip().str.replace(" ","_")

df.isnull().sum()
df.head()
df.describe()
df.info()

print("Correlation Matrix", df.corr())

X = df.drop(['Chance_of_Admit'], axis=1)
Y = df['Chance_of_Admit']

X_train, X_test, Y_train, Y_test = train_test_split(X, Y, test_size=0.2, random_state=0)

model = LinearRegression()
model.fit(X_train, Y_train)
predictions = model.predict(X_test)

print("-----------------------\nLinear Regression Model\n-----------------------")
print("Coefficients:\n\t|", "\n\t|".join([f"{X.columns[i]:17}:\t{model.coef_[i]:.8f}" for i in range(len(X.columns))]))
print("Mean Absolute Error: ", mean_absolute_error(Y_test, predictions))
print("Mean Squared Error: ", mean_squared_error(Y_test, predictions))
print("Root Mean Squared Error: ", np.sqrt(mean_squared_error(Y_test, predictions)))
print("Linear Score: ", model.score(X_test, Y_test))
print("R Score: ", r2_score(Y_test, predictions))
print("Explained Variance Score: ", explained_variance_score(Y_test, predictions))

plt.scatter(Y_test, predictions)
plt.xlabel('True Values')
plt.ylabel('Predictions')
plt.plot(Y_test, Y_test, color='red', linewidth=2)
plt.title('Linear Regression Model')
plt.savefig('a.png')

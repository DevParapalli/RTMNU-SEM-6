import pandas as pd
import os
import pathlib as pl
import matplotlib.pyplot as plt

script_dir = pl.Path(__file__).parent.absolute()
print(f"Script Directory: {script_dir}")
os.chdir(script_dir)

dataset = pd.read_csv("iris.csv")

setosa = dataset[dataset["Species"] == "Iris-setosa"]
versicolor = dataset[dataset["Species"] == "Iris-versicolor"]
virginica = dataset[dataset["Species"] == "Iris-virginica"]

figure, axis = plt.subplots(1, 2)

axis[0].boxplot([setosa["SepalLengthCm"], versicolor["SepalLengthCm"], virginica["SepalLengthCm"]], labels=["Setosa Sepal Length", "Versicolor Sepal Length", "Virginica Sepal Length"])

axis[1].scatter(setosa["SepalLengthCm"], setosa["SepalWidthCm"], color="red", label="Setosa")
axis[1].scatter(versicolor["SepalLengthCm"], versicolor["SepalWidthCm"], color="blue", label="Versicolor")
axis[1].scatter(virginica["SepalLengthCm"], virginica["SepalWidthCm"], color="green", label="Virginica")

plt.show()

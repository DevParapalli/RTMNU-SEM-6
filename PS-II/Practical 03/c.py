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

figure, axis = plt.subplots(1, 3)

axis[0].hist(dataset["SepalLengthCm"], label="Sepal Length Histogram")

axis[1].bar(dataset["SepalLengthCm"], dataset["PetalWidthCm"], label="Sepal Length vs Petal Width")

axis[2].pie(dataset["Species"].value_counts(), labels=["Iris-setosa", "Iris-versicolor", "Iris-virginica"])

plt.show()

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

plt.scatter(dataset["SepalLengthCm"], dataset["SepalWidthCm"], color="black", label="All")

plt.show()

# Save the scatter plot as output
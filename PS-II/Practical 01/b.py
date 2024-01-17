import pandas as pd
import os
import pathlib as pl

script_dir = pl.Path(__file__).parent.absolute()
print(f"Script Directory: {script_dir}")
os.chdir(script_dir)

iris = pd.read_csv('iris.csv')
iris_subset = iris[iris['SepalLengthCm'] > 4.6]
print(f"Subset of iris dataset where SepalLengthCm > 4.6:\n{iris_subset}")
print(f"Mean Sepal Length: {iris.groupby('Species')['SepalLengthCm'].mean()}")

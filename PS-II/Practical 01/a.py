import pandas as pd
import os
import pathlib as pl

script_dir = pl.Path(__file__).parent.absolute()
print(f"Script Directory: {script_dir}")
os.chdir(script_dir)

print("Section A: \n-----------\n")
mtcars = pd.read_csv('mtcars.csv')
print(f"Summary Statistics of mtcars dataset:\n{mtcars.describe()}")
print(f"Structure of mtcars dataset:")
mtcars.info()
print(f"Miles Per Gallon Quantile:\n{mtcars['mpg'].quantile([0.25, 0.5, 0.75])}")

print("\nSection B: \n-----------\n")
cars = pd.read_csv('cars.csv')
print(f"Summary Statistics of cars dataset:\n{cars.describe()}")
print(f"Structure of cars dataset:")
cars.info()
print(f"Quantile of cars dataset:\n{cars['cty'].quantile([0.25, 0.5, 0.75])}")

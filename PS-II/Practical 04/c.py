import pandas as pd
import os
import pathlib as pl
import matplotlib.pyplot as plt
import seaborn as sb
from scipy import stats

script_dir = pl.Path(__file__).parent.absolute()
print(f"Script Directory: {script_dir}")
os.chdir(script_dir)

df = pd.read_csv("iris.csv")

sepal_width_anova = stats.f_oneway(
    df["SepalWidthCm"][df["Species"] == "Iris-setosa"],
    df["SepalWidthCm"][df["Species"] == "Iris-versicolor"],
    df["SepalWidthCm"][df["Species"] == "Iris-virginica"],
)

print(f"Sepal Length ANOVA F-statistic: {sepal_width_anova.statistic}")
print(f"Sepal Length ANOVA p-value: {sepal_width_anova.pvalue}")
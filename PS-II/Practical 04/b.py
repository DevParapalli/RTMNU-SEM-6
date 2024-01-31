import pandas as pd
import os
import pathlib as pl
import matplotlib.pyplot as plt
import seaborn as sb

script_dir = pl.Path(__file__).parent.absolute()
print(f"Script Directory: {script_dir}")
os.chdir(script_dir)

df = pd.read_csv("iris.csv")

# remove species column
del df["Species"], df["Id"]

corr_mat = df.corr()

sb.heatmap(corr_mat, annot=True, cmap="coolwarm", fmt='.2f')
plt.title("Correlation Plot - Iris Dataset")
plt.show()

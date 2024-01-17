import pandas as pd
import pathlib as pl
import os

script_dir = pl.Path(__file__).parent.absolute()
print(f"Script Directory: {script_dir}")
os.chdir(script_dir)

adhyaaya = pd.read_excel('adhyaaya.xlsx')

print(f"Summary Statistics of adhyaaya dataset:\n{adhyaaya.describe()}")
print("Structure of adhyaaya dataset:")
adhyaaya.info()
print(f"Count of values in rzp_status:\n{adhyaaya['rzp_status'].value_counts()}")

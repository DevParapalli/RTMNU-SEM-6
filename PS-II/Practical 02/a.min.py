import requests as r
import zipfile as z
import os 
import pandas as pd
import pathlib as pl

script_dir = pl.Path(__file__).parent.absolute()
print(f"Script Directory: {script_dir}")
os.chdir(script_dir)

response = r.get('https://archive.ics.uci.edu/static/public/45/heart+disease.zip', allow_redirects=True)
print(response.status_code)
with open('_heart-disease-data.zip', 'wb') as f:
    f.write(response.content)

with z.ZipFile('_heart-disease-data.zip', 'r') as zip_ref:
    data = zip_ref.read('processed.cleveland.data').decode('utf-8')
    header = "age,sex,cp,trestbps,chol,fbs,restecg,thalach,exang,oldpeak,slope,ca,thal,heartdisease"
    
    with open('heart-disease.csv', 'w') as f:
        f.write(header + '\n')
        f.write(data)

heart_disease = pd.read_csv('heart-disease.csv')
print(heart_disease.head())

os.remove('_heart-disease-data.zip')


with open(script_dir.parent / 'Practical 01' / 'iris.csv', 'r') as fa:
    with open('iris.csv', 'w') as fb:
        fb.write(fa.read())
    fa.seek(0)
    print(fa.readlines(128))

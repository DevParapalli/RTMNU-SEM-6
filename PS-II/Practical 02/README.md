# Practical 02: Reading and Writing Different Types of Datasets

## Aim

- a. reading different types of datasets (.txt .csv) from Web and disk and writing in file in specific disk location.
- b. reading Excel data sheet in Python.

## Datasets Used

- <https://www.kaggle.com/datasets/redwankarimsony/heart-disease-data> - Cleveland Heart Disease Data Set
    columns: age,sex,cp,trestbps,chol,fbs,restecg,thalach,exang,oldpeak,slope,ca,thal,target
- iris.csv file from previous practical.
    columns: SepalLengthCm, SepalWidthCm, PetalLengthCm, PetalWidthCm, Species
- adhyaaya registrations file in xlsx format
    columns: id,created_at,name,phone,email,edu_institute,edu_year,edu_spl,team,event_id,amount,used,status,rzp_pid,rzp_oid,rzp_sig,rzp_status,custom

## Theory

`pandas` stands out as a robust tool for data analysis and manipulation. Its efficient data structures, such as DataFrames and Series, facilitate the storage and processing of tabular data. Users can leverage pandas to read and write data from various formats (CSV, Excel, SQL databases, etc.) and perform operations like filtering, sorting, merging, aggregation, and statistical analysis.

`openpyxl` focuses on managing Excel files within the Python environment. It enables users to access and modify worksheets, cells, rows, columns, and other Excel elements. With openpyxl, tasks like automatic cell formatting, formula application, chart creation, and more become readily available.

`requests` simplifies network communication tasks, particularly dealing with HTTP requests and fetching data from websites. Users can employ requests to download files, send POST requests, and manage cookies with ease. This library proves invaluable for downloading Excel files from online URLs, scraping data from websites, and interacting with APIs.

`zipfile`, a built-in Python module, excels in handling ZIP archives. It empowers users to read, write, and extract files from ZIP containers. This functionality proves beneficial when downloading or storing multiple files efficiently, as ZIP files compress them for smaller size and optimized management.

## Practical Files

- [a.min.py](./a.min.py)
- [a.py](./a.py)
- [b.py](./b.py)
- *[heart-disease.csv](./heart-disease.csv)
- *[iris.csv](./iris.csv)
- *[adhyaaya.xlsx](./adhyaaya.xlsx)
- @[printed_code_output.pdf](./printed_code_output.pdf)

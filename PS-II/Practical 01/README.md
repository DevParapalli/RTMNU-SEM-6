# Practical 01: Descriptive Statistics

## Aim

- a. Write a program to find basic descriptive statistics using summary, str, quartile function on mtcars and cars datasets.
- b. write an program to find subset of dataset by using subset, aggregate functions on iris dataset.

## Datasets Used

- <https://www.kaggle.com/datasets/leelatte/carscsv> - cars.csv
    Columns: manufacturer, model, displ, year, cyl, trans, drv, cty, hwy, fl, class
- <https://www.kaggle.com/uciml/iris> - iris.csv
    columns: SepalLengthCm, SepalWidthCm, PetalLengthCm, PetalWidthCm, Species
- <https://www.kaggle.com/datasets/ruiromanini/mtcars> - mtcars.csv
    columns: mpg, cyl, disp, hp, drat, wt, qsec, vs, am, gear, carb

## Theory

**Descriptive Statistics:** Descriptive statistics provide a concise summary of essential features of a dataset, including its central tendency, dispersion, shape, and distribution. These statistics are crucial for understanding the characteristics of the data and informing further analysis.

### Key Functions

- `summary()`: Calculates and displays descriptive statistics for numerical variables, including minimum, maximum, quartiles, mean, and median.
str(): Displays the structure of a dataset, revealing variable names, data types, and sample values.
- `quantile()`: Computes specified quantiles (percentiles) of a numerical variable, such as quartiles that divide the data into four equal parts.
- `subset()`: Creates a subset of a dataset based on specified conditions, extracting relevant portions for focused analysis.
- `aggregate()`: Computes summary statistics for numerical variables within subgroups defined by factor variables, enabling group-level comparisons.

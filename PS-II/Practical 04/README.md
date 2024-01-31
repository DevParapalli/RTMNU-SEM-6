# Practical 04: Correlation and Covariance

## Aim

1. Find the correlation matrix.
2. Plot the correlation plot on dataset and visualize giving an overview of relationships among data on iris dataset.
3. Analysis of covariance: variance (ANOVA), if data have categorical variables on iris data.

## Datasets Used

- <https://www.kaggle.com/uciml/iris> - iris.csv
    columns: SepalLengthCm, SepalWidthCm, PetalLengthCm, PetalWidthCm, Species

## Theory

   This is the full theory, it is shortened and written in practical file.

A correlation matrix is a table showing correlation coefficients between variables. It's a square matrix where each cell represents the correlation between two variables. The values range from -1 to 1, where -1 indicates a perfect negative correlation, 1 indicates a perfect positive correlation, and 0 indicates no correlation.

When a correlation matrix is plotted visually, it's often referred to as a correlation plot. In the context of the Iris dataset, which contains features like sepal length, sepal width, petal length, and petal width for different iris flowers, a correlation plot would visually represent the relationships between these variables. For instance, it can help identify if the length of petals and sepals has a positive or negative correlation.

ANOVA (Analysis of Variance) is a statistical method used to analyze the differences among group means in a sample. It assesses whether there are any statistically significant differences between the means of three or more independent groups. If there are categorical variables involved, ANCOVA (Analysis of Covariance) might be employed. ANCOVA combines ANOVA and regression analysis, allowing for the analysis of the impact of categorical variables while statistically controlling for the effects of other continuous variables (covariates). In the case of the Iris dataset, ANOVA could be applied to understand if there are significant differences in the means of certain features among different species of iris.

### Functions Used

- `df.corr()`: This Pandas DataFrame method calculates the correlation matrix for all numerical columns in the DataFrame 'df'. It returns a square matrix where each entry is the correlation coefficient between the corresponding columns.
- `sns.heatmap()`: This Seaborn function creates a heatmap of the correlation matrix. The `annot=True` parameter adds numerical annotations to each cell. The `cmap='coolwarm'` parameter sets the color map, and `fmt=".2f"` formats the annotations to display two decimal places.
- `f_oneway()`: This function from the `scipy.stats` module performs a one-way ANOVA test. It takes multiple arrays (or groups) as arguments, each representing a different category, and returns an ANOVA result object. In the example, it's applied to compare means of the numerical variable for different categories.

## Practical Files

- [a.py](./a.py) - Correlation matrix
- [b.py](./b.py) - Correlation plot
- [c.py](./c.py) - ANOVA
- *[iris.csv](./iris.csv)
- @[b.png](./b.png)
- @[printed_code_output.pdf](./printed_code_output.pdf)
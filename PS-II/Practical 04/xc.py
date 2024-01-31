from scipy.stats import f_oneway

group1 = [1, 2, 3, 4, 5]
group2 = [2, 3, 4, 5, 6]
group3 = [3, 4, 5, 6, 7]

result = f_oneway(group1, group2, group3)

print("F-statistic:", result.statistic)
print("P-value:", result.pvalue)
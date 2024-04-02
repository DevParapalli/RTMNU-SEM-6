import numpy as np
from scipy.stats import chi2_contingency

# Observed data
observed = np.array([[160, 300, 140],
                     [140, 100, 160]])

# Perform the chi-square test
chi2_stat, p_val, dof, expected = chi2_contingency(observed)

# Print the results
print("Chi-square statistic: ", chi2_stat)
print("p-value: ", p_val)
print("Degrees of freedom: ", dof)

# Interpret the results
alpha = 0.05  # Significance level
if p_val < alpha:
    print("There is a significant association between economic condition and IQ level.")
else:
    print("There is no significant association between economic condition and IQ level.")
import scipy.stats as stats
import numpy as np

# IQ scores before training
iq_before = np.array([110, 120, 123, 132, 125])

# IQ scores after training
iq_after = np.array([120, 118, 125, 136, 121])

# Calculate the differences between paired observations
diff = iq_after - iq_before

# Calculate the test statistic and p-value
t_statistic, p_value = stats.ttest_rel(iq_after, iq_before)

# Print the results
print(f"t-statistic: {t_statistic:.4f}")
print(f"p-value: {p_value:.4f}")

# Check if the p-value is less than the significance level (0.01 for 1% level)
alpha = 0.01
if p_value < alpha:
    print("There is a significant change in IQ after training.")
else:
    print("There is no significant change in IQ after training.")
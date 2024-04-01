# Assignment 1

## Program 01

A manufacturer wants to determine the inner diameter of a chalk. Ideally, the diameter should be 57 mm. The data is as follows: 72, 57, 53, 58, 56, 57, 56, 50. Calculate the measures of central value and dispersion, and comment on the quality of the chalk produced.


An IQ test was administered to 5 persons before and after they were trained. IQ before training was 110, 120, 123,132, 125 of 5 persons. After training IQ became 120,118, 125, 136, 121. Test whether there is any change in IQ after training. Given t value at 1% level of significance is 4.6.

### Solution

To solve this problem using Python, we'll need to import the necessary libraries, calculate the measures of central value (mean, median, mode) and measures of dispersion (range, variance, and standard deviation), and then comment on the quality of the chalk produced based on these calculations.

Here's the Python code with detailed comments:

```python
import statistics
from typing import List

def calculate_central_values(data: List[float]) -> tuple:
    """
    Calculate the mean, median, and mode of the given data.

    Args:
        data (List[float]): A list of numerical values.

    Returns:
        tuple: A tuple containing the mean, median, and mode of the data.
    """
    mean = sum(data) / len(data)
    median = statistics.median(data)
    try:
        mode = statistics.mode(data)
    except statistics.StatisticsError:
        mode = "No mode found (data has no repeating values)"

    return mean, median, mode

def calculate_dispersion(data: List[float]) -> tuple:
    """
    Calculate the range, variance, and standard deviation of the given data.

    Args:
        data (List[float]): A list of numerical values.

    Returns:
        tuple: A tuple containing the range, variance, and standard deviation of the data.
    """
    data_range = max(data) - min(data)
    variance = statistics.variance(data)
    std_dev = statistics.stdev(data)

    return data_range, variance, std_dev

def main():
    # Sample data for chalk diameters
    chalk_diameters = [72, 57, 53, 58, 56, 57, 56, 50]

    # Ideal diameter
    ideal_diameter = 57

    # Calculate measures of central value
    mean, median, mode = calculate_central_values(chalk_diameters)
    print(f"Mean diameter: {mean:.2f} mm")
    print(f"Median diameter: {median:.2f} mm")
    print(f"Mode diameter: {mode}")

    # Calculate measures of dispersion
    data_range, variance, std_dev = calculate_dispersion(chalk_diameters)
    print(f"Range: {data_range:.2f} mm")
    print(f"Variance: {variance:.2f}")
    print(f"Standard deviation: {std_dev:.2f} mm")

    # Comment on the quality of the chalk produced
    if mean == ideal_diameter and std_dev == 0:
        print("The chalk produced is of excellent quality, with all diameters equal to the ideal diameter.")
    elif abs(mean - ideal_diameter) <= std_dev:
        print("The chalk produced is of acceptable quality, with the mean diameter within one standard deviation of the ideal diameter.")
    else:
        print("The chalk produced is of poor quality, with the mean diameter deviating significantly from the ideal diameter.")

if __name__ == "__main__":
    main()
```

Here's how the code works:

1. The `calculate_central_values` function calculates the mean, median, and mode of the given data using the `sum`, `statistics.median`, and `statistics.mode` functions, respectively.
2. The `calculate_dispersion` function calculates the range, variance, and standard deviation of the given data using the `max`, `min`, `statistics.variance`, and `statistics.stdev` functions, respectively.
3. In the `main` function, we first define the sample data for chalk diameters and the ideal diameter.
4. We call the `calculate_central_values` function and print the mean, median, and mode of the chalk diameters.
5. We call the `calculate_dispersion` function and print the range, variance, and standard deviation of the chalk diameters.
6. Based on the calculated values, we comment on the quality of the chalk produced by comparing the mean diameter to the ideal diameter and considering the standard deviation.
   - If the mean diameter is equal to the ideal diameter and the standard deviation is zero, we conclude that the chalk produced is of excellent quality.
   - If the absolute difference between the mean diameter and the ideal diameter is less than or equal to the standard deviation, we conclude that the chalk produced is of acceptable quality.
   - If the absolute difference between the mean diameter and the ideal diameter is greater than the standard deviation, we conclude that the chalk produced is of poor quality.

When you run this code, it will output the measures of central value and dispersion, as well as a comment on the quality of the chalk produced based on the given sample data and the ideal diameter of 57 mm.

## Program 02

About 1000 college students are graded according to their IQ level and economic condition. Use the chi-square test to find out whether there is any association between economic condition and the level of IQ.

|      | High | Medium | Low |
| ---- | ---- | ------ | --- |
| Rich | 160  | 300    | 140 |
| Poor | 140  | 100    | 160 |


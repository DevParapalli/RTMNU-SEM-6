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
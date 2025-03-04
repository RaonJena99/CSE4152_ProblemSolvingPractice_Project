import random

# TODO : You can modify the function and argument below.
max_points = 100000
tries = 10
estimated_pis = []

def estimate_pi(max_points):
    in_markers = 0
    pi = 0.
    # Generate random points and check if they are inside the unit circle
    for _ in range(tries):
        points = 0
        for _ in range(max_points):
            x = random.uniform(-1, 1)
            y = random.uniform(-1, 1)
            if x**2 + y**2 <= 1:
                points += 1

        estimated_pi = 4 * points/max_points
        estimated_pis.append(estimated_pi)

    sum_pi = sum(estimated_pis)
    mean_pi = sum_pi/tries

    return mean_pi


# Modify the code to achieve an error rate below 0.1%.
# Print the estimated value of Pi.
print(estimate_pi(max_points))

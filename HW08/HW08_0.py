from typing import List, Tuple
import numpy as np

# TODO: Implement the function to return the nth Fibonacci number and the list of Fibonacci numbers up to n
# The function should take an integer n as input and return a tuple:
# - The first element of the tuple should be the nth Fibonacci number
# - The second element should be a list of all Fibonacci numbers up to the nth number
# For example, if n = 3, the function should return (2, [1, 1, 2])
# It is recommended to use dynamic programming or an iterative approach for efficiency
def fibo(n) -> Tuple[int, List]:
    results = (1, [1])

    if n <= 1: 
        return results
    else:
        results = (1, [1, 1])
        for i in range(2,n):
            tmp = results[1][i-1] + results[1][i-2]
            results[1].append(tmp)
            results = (tmp, results[1])

    return results
    
# Instructions: Complete only the func implementation. You may add print statements to test when using the "Run" button, 
# but only the func will be used for grading upon submission.
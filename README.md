# README: Algorithm Projects Compilation

## Introduction
This document provides an in-depth explanation of multiple algorithm projects, their problem definitions, solutions, and computational complexities. The projects cover various domains of computer science, including dynamic programming, graph theory, computational geometry, and numerical computation. Each project has been implemented in C++ and tested rigorously for correctness and efficiency.

## Table of Contents
1. Project 0: Maximum Subsequence Sum
2. Project 1: Finding Celebrities & Minimum Calculation
3. Project 2: Largest N Numbers & Position of k
4. Project 3: Matrix Addition & Half-Circle Property
5. Project 4: Train Rearrangement & Agony of Engineer
6. Project 5: One Fire Station & Two Fire Stations
7. Project 6: Alternative Random Number Generators
8. Project 7: Delaunay Triangulation & Voronoi Diagram
9. Project 8: Fibonacci Computation with Bitwise Operations
10. Project 9: BFS/DFS-based Problems
11. Project 10: Two Pointers and Sliding Window Applications
12. Project 11: Knapsack Problem & Longest Common Subsequence

---

## Project 0: Maximum Subsequence Sum
### Problem Definition
Given an integer array, find the contiguous subsequence with the maximum sum.

### Algorithm & Complexity
- **Kadane's Algorithm** is used with time complexity **O(n)**.
- Maintains a running sum (`maxtail`) and updates `max_num` accordingly.
- If the running sum becomes negative, reset it to zero.

---

## Project 1: Finding Celebrities & Minimum Calculation
### Problem 1: Finding Celebrities
A person in a group is a celebrity if:
1. Everyone knows them.
2. They know no one.

#### Solution
- The problem is solved using **graph-based elimination**.
- Using pairwise comparisons, a potential candidate is selected.
- Final verification is done in **O(n) time**.

### Problem 2: Minimum Calculation (Exponentiation by Squaring)
Given `a` and `n`, compute `a^n` using minimal multiplications.

#### Solution
- Uses **Divide and Conquer** with recurrence relation:
  - If `n` is even: `a^n = (a^(n/2))^2`
  - If `n` is odd: `a^n = (a^((n-1)/2))^2 * a`
- Time complexity: **O(log n)**

---

## Project 2: Largest N Numbers & Position of k
### Problem 1: Largest N Numbers
Find the largest `N` numbers in an `N×N` matrix where all elements are distinct.

#### Solution
- Uses **Max-Heap (Priority Queue)** for efficient extraction.
- Time Complexity: **O(N² log N)**
- Space Complexity: **O(N²)**

### Problem 2: Position of k
Given a **sorted** `N×N` matrix and a number `k`, determine its position.

#### Solution
- Uses **Binary Search on a 2D Matrix**.
- Converts indices using `(row = index / N, col = index % N)`.
- Time Complexity: **O(log(N²)) = O(2 log N)**.
- Space Complexity: **O(1)**.

---

## Project 3: Matrix Addition & Half-Circle Property
### Problem 1: Matrix Addition
Given an `N×N` matrix, efficiently perform multiple addition queries over submatrices.

#### Solution
- Uses **2D Difference Array** for efficient range updates.
- Complexity: **O(N²) time and space**.

### Problem 2: Half-Circle Property
Given a circle and points on its circumference, determine whether all points lie on the same half-plane.

#### Solution
- Compute angles using **arctangent transformation**.
- Sort the angles and check the largest angle difference.
- Complexity: **O(n log n)** (due to sorting).

---

## Project 4: Train Rearrangement & Agony of Engineer
### Problem 1: Train Rearrangement
Reorder trains arriving in a given order to be in increasing order using a **stack**.

#### Solution
- Uses a **stack-based** approach.
- Time Complexity: **O(n)**.

### Problem 2: Agony of Engineer (Finding Wire Connections)
Identify connections between terminals of two buildings using minimal movements.

#### Solution
- Uses **graph traversal and set operations**.
- Time Complexity: **O(N log N)**.

---

## Project 5: Fire Station Placement Problems
### Problem 1: One Fire Station
Find the optimal location to minimize the **maximum distance** to any building.

#### Solution
- Uses **Tree Diameter and Center** properties.
- Complexity: **O(N)**.

### Problem 2: Two Fire Stations
Find two optimal locations for minimum worst-case distance.

#### Solution
- Uses **Tree Decomposition** and **Diameter Splitting**.
- Complexity: **O(N)**.

---

## Project 6: Alternative Random Number Generators
### Implemented Methods:
- **Xorshift Generator**
- **WELL Generator**
- **Inverse Congruential Generator**
- **Blum-Blum-Shub Generator**

---

## Project 7: Computational Geometry
### Problem 1: Delaunay Triangulation
- Uses **Incremental Construction**.
- Time Complexity: **O(n log n)**.

### Problem 2: Voronoi Diagram Conversion
- Computes **circumcenters** from Delaunay Triangulation.

---

## Project 8: Fibonacci Computation using Bitwise Operations
- Uses **Matrix Exponentiation by Squaring**.
- Complexity: **O(log n)**.

---

## Project 9: BFS/DFS-based Problems
### Example Problems:
- Alphabet Order Discovery
- Eulerian Circuit Validation

---

## Project 10: Efficient Searching Techniques
### Two Pointers
- Used for **Pair Sum Problem**.
- Complexity: **O(n)**.

### Sliding Window
- Used for **Longest Substring Without Repeating Characters**.
- Complexity: **O(n)**.

---

## Project 11: Dynamic Programming Problems
### Problem 1: Knapsack Problem
- Uses **0/1 Knapsack DP**.
- Complexity: **O(nW)**.

### Problem 2: Longest Common Subsequence (LCS)
- Uses **2D DP Table**.
- Complexity: **O(mn)**.

---

## Conclusion
This document outlines multiple projects covering diverse algorithmic techniques. Each project has been implemented with **optimal time complexity** while maintaining **clear, well-structured code**. Future improvements may include parallelized versions of algorithms and heuristics-based optimizations for NP-hard problems.


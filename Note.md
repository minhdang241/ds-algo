# Sliding Window
Pattern: (Longest|Shortest|Number of) (Substrings|Subarrays) with (At most|Exactly) K elements that fit (some condition). This usually requires TC as O(N).
    - Longest -> While loop invalid condition
    - Shortest/Minimum -> While loop valid condition
    - Number of subarray/substring that has atmost/exactly k elements
```
    template:
    for (right = 0; right < n; right++) {
        update window with element at right pointer
        while condition is invalid:
            remove element at the left pointer
        update the global value
    }
```

Pattern: Find the minimum substring in s1 contains string s2 .
```
    template:
    using have and need variable
    cnt = Counter(s2)
    have, need = 0, len(cnt)
    condition:
        while have == need:
```
# Binary Search
Pattern: Find minimum of something and we can discover some kind of monotonicity, for example, if condition(k) is True, then condition(k+1) is also True.
```
    template:
    l, r = min, max
    while l < r:
        m = (l+r)//2
        if condition(m):
            r = m
        else:
            l = m + 1
    return left | left - 1 depends on the problem.
```
Left represents the minimal k satisfying the condition. 

Proof to show that a result is available:
using condition(k) and condition(k-1) with k is the minimal value satisfying the condition. Thus, if condition(k-1) is also True then k should be available to select.

# Two pointers
Technique: two pointers from both ends

# Monotonic stack
Pattern: problem dealing with next greater, previous smaller elements in an array.

There are 4 types of monotonic stacks
- Strictly increasing
- Non-decreasing
- Strictly descreasing
- Non-increasing

|  Problem           |  Stack Type                  |  Operator in while loop |  Assignment Position  |
|--------------------|------------------------------|-------------------------|-----------------------|
|  next greater      |  decreasing (equal allowed)  |  stackTop < current     |  inside while loop    |
|  previous greater  |  decreasing (strict)         |  stackTop <= current    |  outside while loop   |
|  next smaller      |  increasing (equal allowed)  |  stackTop > current     |  inside while loop    |
|  previous smaller  |  increasing (strict)         |  stackTop >= current    |  outside while loop   |
# Graph
1. For directed graph, to detect cycle with DFS we can't use a visited array. Instead, using the COLOR algorithm.
    - LC 1059


# Tree

# BackTracking
Algorithm to find all solutions by incrementally building up candidates to the solutions and abandoning a candidate as soon as it determines the candidates cannot lead to a valid solution

```
def backtrack(candidate):
    if is_valid_solution(candidate):
        output(candidate)
        return
    
    # iterate all possible candidates.
    for next_candidate in list_of_candidates:
        if is_valid(next_candidate):
            # try this partial candidate solution
            place(next_candidate)
            # given the candidate, explore further.
            backtrack(next_candidate)
            # backtrack
            remove(next_candidate)
```

# Dynamic Programming
Question Pattern:
- Asking for optimum value (maximum/minimum/longest/shortest).
- The future decision depends on the earlier decision.

Template:
- Decide the meaning of the function based on the question.
- Find the base case: Ask yourself: What state(s) I can find the solution without DP.

DP Pattern:
- Knapsack
  Given: Items with price and weight.
  Goal: Fill the bag to the max profit.
  Types:
    - 0/1
        Problems:
        Subset sum problem
        Partition equal subset sum
        Count of subsets with sum = X
        Partition a set into 2 subsets such that the difference of subset sum is minimum
        Target Sum
    - Unbounded knapsack
    - Bounded knapsack
- LCS
- LIS
        Problem:
- Matrix chain multiplication
- DP on grid
- Kadane's algorithm












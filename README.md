# Competitive programing training guide
Leetcode: https://leetcode.com/u/minhdg241/

Tips to be competitive:
1. Type Code Faster! (WIP: 110 wpm)
2. Master Programming Languages: Python (WIP) / C++ (WIP)
3. Practice, practice and practice

# Strategy to learn
1. Using Black Box method to learn **how to apply** DS/Algo quickly
    - Step 1: Avoid trying to learn and remember the implementation at the first place.
    - Step 2: Instead, trying to learn how to recognize the pattern and apply the DS/Algo into a problem.
2. Topic-wise for solving hard problems quickly

# Tips / Tricks
## Greedy
- Non-overlapped intervals: choose the one with earliest end time to maximize the number of intervals.
- Medium value yields the minimum operations to make all the values equal.

## Hashing
**Pattern**: compare string or list in O(1) => used to optimize the solution in case TLE.

## Binary Search
**Pattern:** Find minimum of something that we can discover some kind of monotonicity, for example, if condition(k) is True, then condition(k+1) is also True.
- Find minimum of maximum

## Sliding Window
**Pattern:**
- (Longest | Shortest | Number of) (Substrings | Subarrays) with (At most | Exactly) K elements that fit (some condition). 
    - Longest -> While loop invalid condition
    - Shortest/Minimum -> While loop valid condition
    - Number of subarray/substring that has atmost/exactly k elements

- Number of subarray with value in range(l, r) = Number of subarray with value at most r - Number of subarray with value at most l.
**Note**: whenever having some negative sums, use prefix sum with a hashmap instead.

## Monotonic stack
**Pattern:** problem dealing with:
- Next greater, 
- Next smaller, 
- Previous greater. 
- Previous smaller.
- Lexicographically smallest/greatest.
- Histogram related problems.

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

## Graph
**Pattern:**
- Shortest path with positive weights: **Dijkstra**
- Put something before other thing: **Topological sort**
- Detect cycle with DFS in directed graph: **DFS with stack**

## Binary Search Tree (BST)
Inorder traversal -> increasing order.

## BackTracking
**Pattern**: Find all solutions by incrementally building up candidates to the solutions and abandoning a candidate as soon as it determines the candidates cannot lead to a valid solution

## Dynamic Programming
**Pattern:** Asking for optimum value (maximum/minimum/longest/shortest). The future decision depends on the earlier decision.
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
- Matrix chain multiplication:
    - Burst Balloon
- DP on grid
- Kadane's algorithm: find the subarray with maximum value, including the negative and positive elements

**Tips**:
- Optimize the tuple, when using it as a parameter in the recursive function, by bit mask.

## Counting:
- Count the number of solutions for a + b <= t with a in [0,A] and b in [0,B] <br>
  `S(t) - S(t - (A + 1)) - S(t - (B + 1)) + S(t - (A + B + 2)), which S(t) = (t + 1)*(t + 2) // 2`



## Misc
1. How to distribute a sum (s) into an array with lenght of m and each element having values within ranges [0, n]
```
int distributed_mean = s / m;
int mod = s % m;
vector<int> ans(m, distributed_mean);
for (int i = 0; i < mod; i++) {
    ans[i]++;
}
```












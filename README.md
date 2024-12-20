# Competitive programing training guide
Leetcode: https://leetcode.com/u/minhdg241/

Tips to be competitive:
1. Type Code Faster! (DONE)
2. Quickly Identify Problem Types. (WIP)
3. Do Algorithm Analysis. (WIP)
4. Master Programming Languages: Python (DONE) / C++ (WIP)
5. Master The Art Of Testing Code. (WIP)
6. Practice And More Practice. (WIP)


# Strategy to learn
1. Using Black Box method to learn **how to apply** DS/Algo quickly
    - Step 1: Avoid trying to learn and remember the implementation at the first place.
    - Step 2: Instead, trying to learn how to recognize the pattern and apply the DS/Algo into a problem.

# Tips / Tricks
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
- Detect cycle with DFS in directed graph: **COLOR algorithm**

## Binary Search Tree (BST)
Notes: Inorder traversal -> increasing order.

## BackTracking
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
- Matrix chain multiplication
- DP on grid
- Kadane's algorithm

**Tips**:
- Optimize the tuple, when using it as a parameter in the recursive function, by bit mask.

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












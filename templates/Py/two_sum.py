from typing import List


def two_sum(nums: List[int], target: int, start_index: int = 0):
  # nums should be sorted asc
  l, r = start_index, len(nums) - 1
  ans = set()
  while l < r:
    t = nums[l] + nums[r]
    if t == target:
      ans.add((l, r))  # modify this depends on the questions
      r -= 1
      l += 1
    elif t > target:
      r -= 1
    else:
      l += 1
  return ans

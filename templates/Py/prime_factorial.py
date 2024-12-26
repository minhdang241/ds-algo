from math import sqrt
from functools import cache


@cache
def prime_score(num):
  ret = set()
  for i in range(2, int(sqrt(num)) + 1):
    while num % i == 0:
      ret.add(i)
      num //= i
  if num > 1:
    ret.add(num)
  return len(ret)


if __name__ == "__main__":
  assert prime_score(18) == 2

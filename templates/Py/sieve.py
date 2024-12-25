"""
Sieve to collect primes
"""

import math


def sieve_of_primes_up_to(n):
  sieve = [True] * (n + 1)
  sieve[0] = False
  sieve[1] = False
  for p in range(2, round(math.sqrt(n)) + 1):
    if sieve[p]:
      for i in range(p * p, n + 1, p):
        sieve[i] = False
  return sieve


if __name__ == "__main__":
  cnt = 0
  for v in sieve_of_primes_up_to(10):
    if v:
      cnt += 1
  assert cnt == 4

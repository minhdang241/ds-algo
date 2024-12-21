"""
Given pattern s and text t, determine if the pattern appears in the text and if it does, enumerates all its
occurrences in O(s + t)
"""

from __future__ import annotations

import sys


def rabin_karp(s: str, t: str):
  """
  To avoid collision  we can try to use 2 different hashes using different p and/or different m
  """
  p = 31
  m = sys.maxsize
  S = len(s)
  T = len(t)

  # pre-compute power
  p_pow = [0] * max(S, T)
  p_pow[0] = 1
  for i in range(1, len(p_pow)):
    p_pow[i] = (p_pow[i - 1] * p) % m

  h = [0] * (T + 1)
  for i in range(T):
    h[i + 1] = (h[i] + (ord(t[i]) - ord("a") + 1) * p_pow[i]) % m

  hs = 0
  for i in range(S):
    hs = (hs + (ord(s[i]) - ord("a") + 1) * p_pow[i]) % m

  occurrences = []
  for i in range(T - S + 1):
    cur = (h[i + S] + m - h[i]) % m
    if cur == hs * p_pow[i] % m:
      occurrences.append(i)

  return occurrences


if __name__ == "__main__":
  t = "abcdefab"
  s = "ab"
  assert rabin_karp(s, t) == [0, 6]

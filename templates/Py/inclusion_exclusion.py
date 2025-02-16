"""
To count the number of a + b <= t where a in [0, A] and b in [0, B]
"""


def count(A, B, t):
  S = lambda x: 0 if x < 0 else (x + 1) * (x + 2) // 2
  return S(t) - S(t - (A + 1)) - S(t - (B + 1)) + S(t - (A + B + 2))


if __name__ == "__main__":
  t = 5
  A = 2
  B = 3
  assert count(A, B, t) == 12

def build_lps(pa):
  N = len(pa)
  pi = [0] * N
  prev_i = 0
  i = 1
  while i < N:
    if pa[i] == pa[prev_i]:
      pi[i] = prev_i + 1
      i += 1
      prev_i += 1
    else:
      if prev_i == 0:
        pi[i] = 0
        i += 1
      else:
        prev_i = pi[prev_i - 1]
  return pi


if __name__ == "__main__":
  pattern = "abba"
  s = "ababba"
  lps = build_lps(pattern)
  N = len(s)
  i, j, cnt = 0, 0, 0
  while i < N:
    if s[i] == pattern[j]:
      i += 1
      j += 1
    else:
      if j == 0:
        i += 1
      else:
        j = lps[j - 1]
    if j == len(pattern):
      cnt += 1
      j = lps[j - 1]
  assert cnt == 1

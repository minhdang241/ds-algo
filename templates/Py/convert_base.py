def to_base(n, base):
  ans = []
  while n:
    n, r = divmod(n, base)
    if r < 0:
      r += -base
      n += 1
    ans.append(r)
  return ans[::-1] or [0]


if __name__ == "__main__":
  ans = to_base(-3, -2)
  assert ans == [1, 1, 0, 1]

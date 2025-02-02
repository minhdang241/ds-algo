"""Binary Indexed Tree"""


class BIT:
  def __init__(self, arr):
    self.size = len(arr) + 1
    self.tree = [0] * self.size
    for i in range(len(arr)):
      self.add(i, arr[i])

  def add(self, pos, val):
    pos += 1
    while pos < self.size:
      self.tree[pos] += val
      pos = pos + (pos & (-pos))

  def sum(self, pos):
    pos += 1
    res = 0
    while pos > 0:
      res += self.tree[pos]
      pos = pos - (pos & (-pos))
    return res

  def range_sum(self, l, r):
    return self.sum(r) - self.sum(l - 1)


if __name__ == "__main__":
  arr = [5, 2, 9, -3, 5, 20, 10, -7, 2, 3, -4, 0, -2, 15, 5]
  bit = BIT(arr)
  assert bit.sum(6) == 48
  bit.add(4, 10)
  assert bit.sum(7) == 51

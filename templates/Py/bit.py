"""Binary Indexed Tree"""


class BIT:
  def __init__(self, arr):
    self.tree = [0] + arr
    self.size = len(self.tree)
    for i in range(1, self.size):
      pi = i + (i & -i)
      if pi < self.size:
        self.tree[pi] += self.tree[i]

  def add(self, pos, val):
    while pos < self.size:
      self.tree[pos] += val
      pos += pos & -pos

  def sum(self, pos):
    res = 0
    while pos > 0:
      res += self.tree[pos]
      pos -= pos & -pos
    return res


if __name__ == "__main__":
  arr = [5, 2, 9, -3, 5, 20, 10, -7, 2, 3, -4, 0, -2, 15, 5]
  bit = BIT(arr)
  assert bit.sum(7) == 48
  bit.add(4, 10)
  assert bit.sum(8) == 51

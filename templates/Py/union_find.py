class UnionFind:
  def __init__(self, size):
    self.ranks = [1 for _ in range(size)]
    self.roots = [i for i in range(size)]

  def find(self, x):
    if x == self.roots[x]:
      return x
    self.roots[x] = self.find(self.roots[x])
    return self.roots[x]

  def union(self, x, y):
    root_x, root_y = self.find(x), self.find(y)
    if root_x == root_y:
      return

    if self.ranks[root_x] > self.ranks[root_y]:
      self.roots[root_y] = root_x
    elif self.ranks[root_x] < self.ranks[root_y]:
      self.roots[root_x] = root_y
    else:
      self.roots[root_y] = root_x
      self.ranks[root_x] += 1

  def connected(self, x, y):
    return self.find(x) == self.find(y)

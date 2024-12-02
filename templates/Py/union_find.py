class UnionFind:
  def __init__(self, size):
    self.rank = [1 for _ in range(size)]
    self.root = [i for i in range(size)]

  def find(self, x):
    if x == self.root[x]:
      return x
    self.root[x] = self.find(self.root[x])
    return self.root[x]

  def union(self, x, y):
    root_x, root_y = self.find(x), self.find(y)

    if self.rank[root_x] > self.rank[root_y]:
      self.root[root_y] = root_x
    elif self.rank[root_x] < self.rank[root_y]:
      self.root[root_x] = root_y
    else:
      self.root[root_y] = root_x
      self.rank[root_x] += 1

  def connected(self, x, y):
    return self.find(x) == self.find(y)

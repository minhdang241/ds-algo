from collections import defaultdict, deque


def bfs(graph, weights, source, target=None):
  q = deque([(0, source)])
  dists = defaultdict(lambda: float("inf"))
  prevs = defaultdict(lambda: None)
  dists[source] = 0
  visit = {source}
  while q:
    dist, node = q.popleft()
    if node == target:
      break
    for neigbour in graph[node]:
      if neigbour not in visit:
        visit.add(neigbour)
        new_dist = dist + weights[node][neigbour]
        dists[neigbour] = new_dist
        prevs[neigbour] = node
        q.append((new_dist, neigbour))
  return dists, prevs


if __name__ == "__main__":
  # edges = [(0, 1, 2), (0, 2, 6), (0, 3, 7), (1, 3, 3),
  #  (1, 4, 6), (2, 4, 1), (3, 4, 5)]
  edges = [
    [3, 1, 3],
    [3, 2, 1],
    [3, 0, 2],
    [1, 4, 6],
  ]
  graph = defaultdict(list)
  weights = defaultdict(lambda: defaultdict(int))
  for fr, to, weight in edges:
    graph[fr].append(to)
    graph[to].append(fr)
    weights[fr][to] = weight
    weights[to][fr] = weight
  source = 3
  target = None
  dists, prevs = bfs(graph, weights, source, target)
  #   print(dists)
  assert dists[4] == 9

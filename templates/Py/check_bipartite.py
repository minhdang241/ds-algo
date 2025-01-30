"""Check if a graph is bipartite a.k.a can be coloring with 2 colors"""

from collections import defaultdict


def is_bipartite(node, graph, colors):
  for nei in graph[node]:
    if colors[nei] == colors[node]:
      return False
    if colors[nei] != -1:
      continue
    colors[nei] = (colors[node] + 1) % 2
    if not is_bipartite(nei, graph, colors):
      return False
  return True


def build_graph(edges):
  G = defaultdict(list)
  for a, b in edges:
    G[a].append(b)
    G[b].append(a)
  return G


if __name__ == "__main__":
  n = 6
  edges = [[1, 2], [1, 4], [1, 5], [2, 6], [2, 3], [4, 6]]
  G = build_graph(edges)

  colors = defaultdict(lambda: -1)
  for node in range(1, n + 1):
    if colors[node] == -1:
      colors[node] = 0
      assert is_bipartite(node, G, colors) == True

  n = 3
  edges = [[1, 2], [2, 3], [3, 1]]
  G = build_graph(edges)
  colors = defaultdict(lambda: -1)
  for node in range(1, n + 1):
    if colors[node] == -1:
      colors[node] = 0
      assert is_bipartite(node, G, colors) == False

from collections import defaultdict


def topo_sort(graph, size):
  visited = set()
  order = []

  def dfs(node):
    nonlocal order, visited
    if node not in visited:
      visited.add(node)
    for neighbor in graph[node]:
      if neighbor not in visited:
        dfs(neighbor)

    order.append(node)
    return order

  for node in range(size):
    if node not in visited:
      dfs(node)

  return order[::-1]


if __name__ == "__main__":
  graph = {0: [2, 1], 1: [3], 2: [3, 5], 5: [], 4: [], 3: [4], 6: [], 7: []}
  order = topo_sort(graph, len(graph))
  print(order)
  assert order == [7, 6, 0, 1, 2, 5, 3, 4]

"""Using DFS to check cycle in DAG"""

from collections import defaultdict


def have_cycle(graph, node, stack, seen):
  seen.add(node)
  stack.add(node)
  for nei in graph[node]:
    if nei not in seen:
      if have_cycle(graph, nei, stack, seen):
        return True
    else:
      if nei in stack:
        return True
  stack.remove(node)
  return False


if __name__ == "__main__":
  G = {0: [1, 2], 1: [0, 2], 2: [2, 3], 3: []}
  assert have_cycle(G, 0, set(), set()) == True
  assert have_cycle(G, 1, set(), set()) == True
  assert have_cycle(G, 2, set(), set()) == True
  assert have_cycle(G, 3, set(), set()) == False

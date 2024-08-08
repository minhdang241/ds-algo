from collections import defaultdict
from typing import List

def treeDiameter(edges: List[List[int]]) -> int:
    """
    Find the furthest node from the first node.
    Find the furthest node from the found node from step 1.    G = defaultdict(list)
    """
    for a, b in edges:
        G[a].append(b)
        G[b].append(a)

    max_val = 0
    f_node = 0
    visited = set()

    def dfs(node, visited, G, l):
        nonlocal max_val, f_node
        visited.add(node)

        if l > max_val:
            max_val = l
            f_node = node

        for neighbor in G[node]:
            if neighbor not in visited:
                dfs(neighbor, visited, G, l + 1)

    dfs(0, visited, G, 0)
    
    visited = set()
    dfs(f_node, visited, G, 0)
    return max_val

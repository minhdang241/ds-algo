from collections import defaultdict
import heapq


def dijkstra(graph, weights, source, target=None):
    pq = [(0, source)]
    dists = defaultdict(lambda: float("inf"))
    prevs = defaultdict(lambda: None)
    dists[source] = 0
    while pq:
        dist, node = heapq.heappop(pq)
        if dist > dists[node]:
            continue
        # if node == target:
            # break
        for neigbour in graph[node]:
            new_dist = dist + weights[node][neigbour]
            if new_dist >= dists[neigbour]:
                continue
            dists[neigbour] = new_dist
            prevs[neigbour] = node
            heapq.heappush(pq, (new_dist, neigbour))
    return dists, prevs


if __name__ == "__main__":
    # edges = [(0, 1, 2), (0, 2, 6), (0, 3, 7), (1, 3, 3),
            #  (1, 4, 6), (2, 4, 1), (3, 4, 5)]
    edges = [
        [0, 1, 3],
        [0, 2, 3],
        [0, 4, 5],
        [1, 5, 4],
        [2, 1, 3],
        [2, 5, 3],
        [3, 0, 4],
        [3, 4, 6],
        [4, 2, 1],
        [4, 6, 5],
        [5, 7, 3],
        [6, 5, 5],
        [6, 7, 1]
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
    dists, prevs = dijkstra(graph, weights, source, target)
    print(dists)
    assert(dists[7] == 12)
    # assert (dists == {0: 0, 1: 2, 2: 6, 3: 5, 4: 7})
    # assert (prevs == {1: 0, 2: 0, 3: 1, 4: 2})

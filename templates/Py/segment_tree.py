from __future__ import annotations


class SegTree:
    def __init__(self, t):
        self.t = t

    def build(self, a, v, tl, tr):
        t = self.t
        if tl == tr:
            t[v] = a[tl]
        else:
            tm = (tl + tr) // 2
            self.build(a, v * 2, tl, tm)
            self.build(a, v * 2 + 1, tm + 1, tr)
            t[v] = max(t[v * 2], t[v * 2 + 1])

    def query(self, v, l, r, tl, tr):
        t = self.t
        if l > r:
            return 0
        if l == tl and r == tr:
            return t[v]

        tm = (tl + tr) // 2
        return max(
            self.query(v * 2, l, min(r, tm), tl, tm),
            self.query(v * 2 + 1, max(l, tm + 1), r, tm + 1, tr),
        )

    def update(self, v, tl, tr, pos, new_val):
        t = self.t
        if tl == tr:
            t[v] = new_val
        else:
            tm = (tl + tr) // 2
            if pos <= tm:
                self.update(v * 2, tl, tm, pos, new_val)
            else:
                self.update(v * 2 + 1, tm + 1, tr, pos, new_val)
            t[v] = max(t[v * 2], t[v * 2 + 1])

    def __str__(self):
        return str(self.t)


if __name__ == "__main__":
    li = [2, 4, 2, 5, 6]
    # queries = [[2, 1, 4], [2, 5, 6], [1, 2, 3], [2, 1, 4]]
    queries = [[2, 1, 4], [2, 1, 1], [2, 1, 2]]
    N = len(li)
    INF = float("inf")
    t = [INF] * (4 * N)
    segtree = SegTree(t)
    segtree.build(li, 1, 0, N - 1)
    print(segtree)
    for q in queries:
        ty, a, b = q
        if ty == 1:
            a -= 1
            segtree.update(1, 0, N - 1, a, b)
        else:
            a -= 1
            b -= 1
            print(segtree.query(1, a, b, 0, N - 1))
    print(segtree)

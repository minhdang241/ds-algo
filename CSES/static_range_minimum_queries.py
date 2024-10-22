n, q = map(int, input().split())
a = list(map(int, input().split()))

INF = float("inf")
t = [INF] * (4 * n)

def build(a, node_i, tl, tr):
    if tl == tr:
        t[node_i] = a[tl]
    else:
        tm = (tl + tr) // 2
        build(a, node_i * 2, tl, tm)
        build(a, node_i * 2 + 1, tm + 1, tr)
        t[node_i] = min(t[node_i*2], t[node_i*2 + 1])


def query(node_i, tl, tr, l, r):
    if l > r:
        return INF
    if l == tl and r == tr:
        return t[node_i]

    tm = (tl + tr) // 2
    return min(query(node_i*2, tl, tm, l, min(tm, r)),
               query(node_i*2 + 1, tm + 1, tr, max(l, tm + 1), r))


def update(node_i, tl, tr, pos, new_val):
    if tl == tr:
        t[node_i] = new_val
    else:
        tm = (tl + tr) // 2
        if pos <= tm:
            update(node_i*2, tl, tm, new_val)
        else:
            update(node_i*2 + 1, tl, tm, new_val)
        t[node_i] = min(t[node*2], t[node*2+1])
    

build(a, 1, 0, n -1)

for _ in range(q):
    a, b = map(int, input().split())
    a -= 1
    b -= 1
    print(query(1, 0, n - 1, a, b))



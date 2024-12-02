n, q = map(int, input().split())
INF = float("inf")

t = [INF] * (4 * n)


def build(a, v, tl, tr):
  if tl == tr:
    t[v] = a[tl]
  else:
    tm = (tl + tr) // 2
    build(a, v * 2, tl, tm)
    build(a, v * 2 + 1, tm + 1, tr)
    t[v] = min(t[v * 2], t[v * 2 + 1])


def query(v, l, r, tl, tr):
  if l > r:
    return INF
  if l == tl and r == tr:
    return t[v]

  tm = (tl + tr) // 2
  return min(query(v * 2, l, min(r, tm), tl, tm), query(v * 2 + 1, max(l, tm + 1), r, tm + 1, tr))


def update(v, tl, tr, pos, new_val):
  if tl == tr:
    t[v] = new_val
  else:
    tm = (tl + tr) // 2
    if pos <= tm:
      update(v * 2, tl, tm, pos, new_val)
    else:
      update(v * 2 + 1, tm + 1, tr, pos, new_val)
    t[v] = min(t[v * 2], t[v * 2 + 1])


li = list(map(int, input().split()))
build(li, 1, 0, n - 1)
for _ in range(q):
  ty, a, b = map(int, input().split())

  if ty == 1:
    a -= 1
    update(1, 0, n - 1, a, b)
  else:
    a -= 1
    b -= 1
    print(query(1, a, b, 0, n - 1))

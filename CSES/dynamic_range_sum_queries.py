n, q = map(int, input().split())

t = [0] * (4 * n)

a = list(map(int, input().split()))


def build(a, v, tl, tr):
  if tl == tr:
    t[v] = a[tl]
  else:
    tm = (tl + tr) // 2
    build(a, v * 2, tl, tm)
    build(a, v * 2 + 1, tm + 1, tr)
    t[v] = t[v * 2] + t[v * 2 + 1]


def sum(v, tl, tr, l, r):
  if l > r:
    return 0
  if l == tl and r == tr:
    return t[v]
  tm = (tl + tr) // 2
  return sum(v * 2, tl, tm, l, min(r, tm)) + sum(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r)


def update(v, tl, tr, pos, new_val):
  if tl == tr:
    t[v] = new_val
  else:
    tm = (tl + tr) // 2
    if pos <= tm:
      update(v * 2, tl, tm, pos, new_val)
    else:
      update(v * 2 + 1, tm + 1, tr, pos, new_val)
    t[v] = t[v * 2] + t[v * 2 + 1]


build(a, 1, 0, n - 1)
for _ in range(q):
  _type, a, b = map(int, input().split())
  if _type == 1:
    a -= 1
    update(1, 0, n - 1, a, b)
  else:
    a -= 1
    b -= 1
    print(sum(1, 0, n - 1, a, b))

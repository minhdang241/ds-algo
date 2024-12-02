from __future__ import annotations


def perm(a, left, right):
  if left == right:
    print(a)
    return

  for i in range(left, right + 1):
    a[left], a[i] = a[i], a[left]
    perm(a, left + 1, right)
    a[left], a[i] = a[i], a[left]


if __name__ == "__main__":
  perm([20, 24, 90], 0, 2)

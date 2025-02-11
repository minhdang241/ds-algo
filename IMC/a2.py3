from collections import Counter
n = int(input())

l = list(map(int, input().split()))


def main():
  cnt = Counter(l)
  ma = 0
  for k, v in cnt.items():
    if k == v:
      ma = max(ma, k)
  print(ma)

main()

(n, t) = list(map(int, input().split()))
ropes = list(map(int, input().split()))

ropes.sort()

seen = set()
def main():
  for i in range(n):
    other = t - ropes[i]
    if other in seen:
      print("YES")
      print(ropes[i], other)
      return
    else:
      seen.add(ropes[i])
  
  print("NO")

main()







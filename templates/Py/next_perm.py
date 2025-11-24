def gen_perms(v):
  stack = [([], v)]
  while stack:
    perm, rem = stack.pop()
    if not rem:
      print(perm)
      continue
    for i in range(len(rem) - 1, -1, -1):
      stack.append((perm + [rem[i]], rem[:i] + rem[i + 1 :]))


if __name__ == "__main__":
  gen_perms([1, 2, 3])

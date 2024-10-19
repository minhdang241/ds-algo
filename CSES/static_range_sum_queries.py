n, q = map(int, input().split())

li = list(map(int, input().split()))

prefix_sum = [0] * n
for i, v in enumerate(li):
	prefix_sum[i] += v 
	if i - 1 >= 0:
		prefix_sum[i] += prefix_sum[i-1]

prefix_sum = [0] + prefix_sum
for _ in range(q):
    a, b = map(int, input().split())
    print(prefix_sum[b] - prefix_sum[a-1])

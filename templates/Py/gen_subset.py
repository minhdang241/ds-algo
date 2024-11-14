from __future__ import annotations


def gen_subset(n):
    ma = 1 << n
    for i in range(ma):
        l = []
        for j in range(n):
            if i & (1 << j) != 0:
                print(i)
                l.append(j)
        print(l)


if __name__ == "__main__":
    gen_subset(3)

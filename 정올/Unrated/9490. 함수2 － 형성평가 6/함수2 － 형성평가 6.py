def swap(n, a, b):
    egg = list(range(n + 1))
    egg[a], egg[b] = egg[b], egg[a]
    return egg

n = int(input())
a, b = map(int, input().split())

l = swap(n, a, b)
print(*l)
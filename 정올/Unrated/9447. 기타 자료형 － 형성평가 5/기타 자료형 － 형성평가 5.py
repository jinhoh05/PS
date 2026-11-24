A = set(map(int, input().split()))
B = map(int, input().split())

for c in B:
    print(1 if c in A else 0, end=" ")
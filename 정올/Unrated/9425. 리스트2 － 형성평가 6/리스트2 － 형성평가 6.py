A = [input().split() for _ in range(3)]

for r in A:
    for ch in r:
        print(chr(ord(ch) + 32), end=' ')
    print()
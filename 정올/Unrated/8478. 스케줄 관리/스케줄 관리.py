n = int(input())

task = []
for i in range(n):
    h, m, t = input().split()
    h = int(h)
    m = int(m)
    print(f"{t}({h:02d}:{m:02d})", end="")
    if i < n-1:
        print("->",end="")


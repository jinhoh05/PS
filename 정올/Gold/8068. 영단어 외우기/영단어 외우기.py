n, m, q = map(int, input().split())
a = list(map(int, input().split()))
li = [0]*(n+100000)
for i in range(n):
    if a[i]%m > 0 and a[i] >= m:
        li[i+1] += m
        li[i+1+a[i]//m] -= m-a[i]%m
        li[i+2+a[i]//m] -= a[i]%m
    elif a[i]%m == 0 and a[i] >= m:
        li[i+1] += m
        li[i+1+a[i]//m] -= m
    else:
        li[i+1] += a[i]
        li[i+2] -= a[i]
for i in range(n+99999):
    li[i+1] += li[i]
for i in range(n-1):
    a[i+1] += a[i]
licp = li[:]
for i in range(n+99999):
    licp[i+1] += licp[i]
for i in range(q):
    x, y = map(int, input().split())
    if x == 1:
        print(a[y-1] - licp[y-1])
    else:
        print(li[y-1])
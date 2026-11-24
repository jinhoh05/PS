A = []
n = int(input())
pre = int(input())
flag = True
for _ in range(1, n):
    num = int(input())
    if num <= pre:
        flag = False
        break
    pre = num

if flag is True:
    print("YES")
else:
    print("NO")
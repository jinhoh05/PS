n = int(input())
num = 1
for i in range(n):
    for j in range(n):
        print(num, end=" ")
        num += 2
        num %= 10
    print()
n = int(input())
A = [[0] * n for _ in range(n)]

for i in range(n):
    A[i][0] = 1
    A[i][i] = 1

for i in range(2, n):
    for j in range(1, i):
        A[i][j] = A[i - 1][j - 1] + A[i - 1][j]

for i in range(n - 1, -1, -1):
    print(*A[i][:i + 1])
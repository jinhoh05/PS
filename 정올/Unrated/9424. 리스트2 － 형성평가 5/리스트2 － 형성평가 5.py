A = [[0] * 5  for _ in range(5)]
A[0][0] = A[0][2] = A[0][4] = 1
for i in range (1, 5):
    for j in range(0, 5):
        l = A[i-1][j-1] if j-1 >= 0 else 0
        r = A[i-1][j+1] if j+1 < 5 else 0
        A[i][j] = l + r
for r in A:
    print(*r)
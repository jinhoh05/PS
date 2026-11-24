A = []
n = int(input())
for _ in range(n):
    A.append(int(input()))
k = int(input())
for i in range(n):
    if A[i] == k:
        print(i+1, end = " ")

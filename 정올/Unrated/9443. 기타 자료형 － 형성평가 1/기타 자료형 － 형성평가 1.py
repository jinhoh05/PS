n = int(input())
A = []
for i in range(n):
    name, age = input().split()
    A.append((name, int(age)))

print(A)
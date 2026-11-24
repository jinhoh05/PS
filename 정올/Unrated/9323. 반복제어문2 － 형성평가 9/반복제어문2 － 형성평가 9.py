n = int(input())
m = int(input())

for j in range(1, 10):
    if n > m:
        for i in range(n, m-1, -1):
            print(f"{i} * {j} = {i*j}", end = "   ")
    else:
        for i in range(n, m+1, 1):
            print(f"{i} * {j} = {i*j}", end = "   ")    
    print()
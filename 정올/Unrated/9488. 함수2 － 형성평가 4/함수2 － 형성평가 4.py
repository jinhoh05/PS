def f(a):
    return len(a)

a = input().split()

for i in range(3):
    a[i] = f(a[i])
    
print(a)
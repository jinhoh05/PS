n = int(input())
d = {}

for _ in range(n):
    k, name = input().split()
    k = int(k)
    if k == 1:
        if d.get(name) == None:
            d[name] = 1 
        else:
             d[name] += 1
    else:
        if d.get(name) == None:
            print(0)
        else:
            print(d.get(name))
            d.pop(name)

print(d)
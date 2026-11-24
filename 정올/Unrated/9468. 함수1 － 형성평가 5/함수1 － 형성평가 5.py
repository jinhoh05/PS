def sq(a, b):
    temp = a**2 - b**2 if a>b else b**2 - a**2
    return temp

a, b = map(int, input().split())
print(sq(a,b))
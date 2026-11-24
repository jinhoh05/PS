n = int(input())

if n % 400 == 0:
    print("leap year")
elif n % 100 == 0:
    print("common year")
elif n % 4 == 0:
    print("leap year")
else:
    print("common year")
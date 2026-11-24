while True:
    a = input().split()

    if a[0] == "done":
        break

    if a[0] == "int":
        a = list(map(int, a[1:]))
    else:
        a = list(map(float, a[1:]))

    print(a)
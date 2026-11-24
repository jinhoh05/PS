sum = 0
cnt = 0
while True:
    a = int(input())
    if a < 1 or a > 5:
        break;
    if a % 2 == 0:
        sum += a
        cnt += 1
print(sum // cnt)
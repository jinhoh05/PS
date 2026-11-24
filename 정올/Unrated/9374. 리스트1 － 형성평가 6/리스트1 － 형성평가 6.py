odd = []
even = []
for _ in range(100):
    num = int(input())
    if num == 0:
        break
    if num % 2 == 0:
        even.append(num)
    else:
        odd.append(num)
print("odd =", odd)
print("even =", even)
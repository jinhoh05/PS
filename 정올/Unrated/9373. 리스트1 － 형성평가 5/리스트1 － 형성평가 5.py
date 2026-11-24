A = []
while True:
    a = int(input())
    if a == 0:
        break
    if a % 5 == 0:
        A.append(a)
print(A)
print(f"CNT:", len(A))
print(f"HAP:", sum(A))
print(f"AVG: {sum(A)/len(A):.1f}")
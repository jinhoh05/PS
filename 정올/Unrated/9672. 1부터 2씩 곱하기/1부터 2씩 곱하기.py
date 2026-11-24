sum = 0
def hap(k):
    global sum
    if k < n:
        sum += k
    else:
        return
    hap(k*2)

n = int(input())

hap(1)
print(sum)
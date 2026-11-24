sum = 1

def mult(num):
    global sum

    if num == 0:
        return
    k = num % 10
    
    if k != 0:
        sum = sum * k
    mult(num//10)

l = input().split()
a = 1
for num in l:
    a *= int(num)
mult(a)
print(sum)
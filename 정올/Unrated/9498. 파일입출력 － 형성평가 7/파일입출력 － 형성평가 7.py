f = open("input.txt", "r")
s, e = map(int, f.readline().split())
f.close()

cnt = 0

for y in range(s, e + 1):
    if y % 400 == 0 or (y % 4 == 0 and y % 100 != 0):
        cnt += 1

g = open("output.txt", "w")
g.write(str(cnt))
g.close()
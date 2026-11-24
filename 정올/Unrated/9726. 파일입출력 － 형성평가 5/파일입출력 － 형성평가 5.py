f = open("input.txt", "r")
a = list(map(int, f.readline().split()))
f.close()

ans = []

for x in a:
    if x % 15 == 0:
        ans.append(x)

g = open("output.txt", "w")

if len(ans) == 0:
    g.write("0")
else:
    for x in ans:
        g.write(str(x) + " ")
    g.write("\n")
    g.write(str(len(ans)))

g.close()
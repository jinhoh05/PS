f = open("input.txt", "r")
n = int(f.readline())
f.close()

g = open("output.txt", "w")

for i in range(1, n + 1):
    g.write("  " * (n - i))
    g.write("* " * (2 * i - 1))
    g.write("\n")

for i in range(n - 1, 0, -1):
    g.write("  " * (n - i))
    g.write("* " * (2 * i - 1))
    g.write("\n")

g.close()
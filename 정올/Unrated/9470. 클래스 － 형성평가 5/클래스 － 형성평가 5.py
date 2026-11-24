class people:
    def __init__(self, name, height, weight):
        self.name = name
        self.height = int(height)
        self.weight = float(weight)

a = []

for i in range(5):
    a.append(people(*input().split()))

a.sort(key=lambda p: (p.height, p.weight))

for p in a:
    print(p.name)
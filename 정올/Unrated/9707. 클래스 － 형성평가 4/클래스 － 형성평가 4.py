class people:
    def __init__(self, name, age):
        self.name = name
        self.age = int(age)

n = int(input())
a = []
for i in range(n):
    a.append(people(*input().split()))

age = max(p.age for p in a)

for p in a:
    if p.age == age:
        print(p.name, end=" ")
class animal:
    def __init__(self, kind, name, age):
        self.kind = kind
        self.name = name
        self.age = age
    def p(self):
        print("Type:", self.kind)
        print("Name:", self.name)
        print("Age:", self.age)

a = animal(*input().split())
a.p()
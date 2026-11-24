import re
n=int(input())
for i in range(n):
    a=input().strip()
    if re.search(r'^https?://[a-zA-Z0-9-]+(\.[a-zA-Z0-9-]+)+(/[a-zA-Z0-9-]+([.=?/][a-zA-Z0-9-]+)*[?=.]?)?$',a):        print('True')
    else:
        print('False')
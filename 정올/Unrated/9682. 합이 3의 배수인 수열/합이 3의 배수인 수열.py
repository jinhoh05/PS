n, m = map(int, input().split())

used = [False] * (m + 1)
arr = []
cnt = 0

def dfs():
    global cnt

    if len(arr) == n:
        if sum(arr) % 3 == 0:
            cnt += 1
        return

    for i in range(1, m + 1):
        if not used[i]:
            used[i] = True
            arr.append(i)

            dfs()

            arr.pop()
            used[i] = False

dfs()
print(cnt)
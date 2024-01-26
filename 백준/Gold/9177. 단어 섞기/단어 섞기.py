n = int(input())

for i in range(1, n + 1):
    a, b, c = map(str, input().split())
    if len(c) != len(b) + len(a):
        print("Data set " + i +": no")
        continue
    visited = [[0] * (len(b) + 1) for _ in range(len(a) + 1)]
    flag = False
    q = [(0, 0)]
    while len(q) > 0:
        i1, i2 = q.pop(0)
        if i1 + i2 == len(c):
            flag = True
            break
        if i1 < len(a) and visited[i1 + 1][i2] == 0 and a[i1] == c[i1 + i2]:
            visited[i1 + 1][i2] = 1
            q.append((i1 + 1, i2))
        if i2 < len(b) and visited[i1][i2 + 1] == 0 and b[i2] == c[i1 + i2]:
            visited[i1][i2 + 1] = 1
            q.append((i1, i2 + 1))
    if flag:
        print("Data set " + str(i) +": yes")
    else:
        print("Data set " + str(i) +": no")
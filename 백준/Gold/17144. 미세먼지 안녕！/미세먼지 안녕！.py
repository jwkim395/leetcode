r, c, t = map(int, input().split())
board = []
for _ in range(0, r):
    row = list(map(int, input().split()))
    board.append(row)
    
up = -1
down = -1
for i in range(r):
    if board[i][0] == -1:
        up = i
        down = i + 1
        break

for _ in range(0, t):
    update_board = [[0] * c for _ in range(r)]
    dx = [1, 0, -1, 0]
    dy = [0, 1, 0, -1]
    # 먼지
    for i in range(0, r):
        for j in range(0, c):
            if board[i][j] > 0:
                temp = 0
                for q in range(0, 4):
                    nx = dx[q] + i
                    ny = dy[q] + j
                    if 0 <= nx < r and 0 <= ny < c and board[nx][ny] != -1:
                        update_board[nx][ny] += (board[i][j] // 5)
                        temp += (board[i][j] // 5)
                board[i][j] -= temp
    # update
    for i in range(0, r):
        for j in range(0, c):
            board[i][j] += update_board[i][j]
    
    # air
    dx = [0, -1, 0, 1]
    dy = [1, 0, -1, 0]
    st = [up, 1]
    prev = board[up][1]
    board[up][1] = 0
    idx = 0
    while idx < 4:
        nx = dx[idx] + st[0]
        ny = dy[idx] + st[1]
        if 0 <= nx < r and 0 <= ny < c and board[nx][ny] != -1:
            temp = board[nx][ny]
            board[nx][ny] = prev
            prev = temp
            st[0] = nx
            st[1] = ny
        else:
            idx += 1
                
    dx = [0, 1, 0, -1]
    dy = [1, 0, -1, 0]
    st = [down, 1]
    prev = board[down][1]
    board[down][1] = 0
    idx = 0
    while idx < 4:
        nx = dx[idx] + st[0]
        ny = dy[idx] + st[1]
        if 0 <= nx < r and 0 <= ny < c and board[nx][ny] != -1:
            temp = board[nx][ny]
            board[nx][ny] = prev
            prev = temp
            st[0] = nx
            st[1] = ny
        else:
            idx += 1
ans = 0
for i in range(0, r):
    for j in range(0, c):
        if 0 < board[i][j]:
            ans += board[i][j]
print(ans)
                
                
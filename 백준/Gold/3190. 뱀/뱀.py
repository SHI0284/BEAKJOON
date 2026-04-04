from collections import deque

n = int (input())

board = [[0]* n for i in range(n)] # 보드판 생성ㅎ마

k = int(input())   # 사과 개수 입력받음

for i in range(k):
    row, col = map(int, input().split())
    board[row-1][col-1] = 1 

# 방향 전환 횟수
num = int(input()) 

# 방향 전환 정보 저장하는 부분임
# key: 시간, value = 'L' or 'D'
turn = {}
for i in range(num):
    x, c = input().split()
    turn[int(x)] = c

# 방향: 오른쪽, 아래, 왼쪽, 위
dr = [0, 1, 0, -1]
dc = [1, 0, -1, 0]

direction = 0 # 처음에는 오른쪽
time = 0      # 현재 시간

# 뱀의 몸을 deque로 관리
# 맨 앞: 꼬리
# 맨 뒤: 머리
snake = deque()
snake.append((0, 0))
board[0][0] = 2  # 시작 위치에 뱀 표시

while True:
    time += 1

    # 현재 머리 위치
    head_r, head_c = snake[-1]

    # 다음 머리 위치
    nr = head_r + dr[direction]
    nc = head_c + dc[direction]

    # 벽에 부딪히면 종료
    if nr < 0 or nr >= n or nc < 0 or nc >= n:
        print(time)
        break

    # 자기 몸에 부딪히면 종료
    if board[nr][nc] == 2:
        print(time)
        break

    # 사과가 있으면
    if board[nr][nc] == 1:
        snake.append((nr, nc))
        board[nr][nc] = 2
        # 사과를 먹었으므로 꼬리는 그대로 둠 -> 길이 증가

    # 사과가 없으면
    else:
        snake.append((nr, nc))
        board[nr][nc] = 2

        # 꼬리 제거
        tail_r, tail_c = snake.popleft()
        board[tail_r][tail_c] = 0

    # 현재 시간이 방향 전환 시간이라면 회전
    if time in turn:
        if turn[time] == 'D':   # 오른쪽 회전
            direction = (direction + 1) % 4
        else:                   # 왼쪽 회전
            direction = (direction - 1) % 4
def fun(x,y,board):
    for i in range(len(board)):
        for j in range(len(board[0])):
            if x==i or y==j or abs(i-x)==abs(j-y):
                board[i][j] = 0

n,m,k = map(int,input().split(' '))
board = [[1]*m]*n
for i in range(k):
    x,y = map(int,input().split(' '))
    fun(x,y,board)
res = 0
for i in range(len(board)):
    for j in range(len(board[0])):
        res+=board[i][j]
print(res)
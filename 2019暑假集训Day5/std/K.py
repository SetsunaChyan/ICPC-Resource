MAXN = 405
S = [[0] * MAXN for i in range(MAXN)] # 定义一个二维列表(二位数组)
for i in range(1, MAXN):
    S[i][i] = S[i][1] = 1
    for j in range(2, i):
        S[i][j] = S[i - 1][j - 1] + j * S[i - 1][j]
while True:     # 多组数据
    try:
        n, m = map(int,input().split())
        print(S[n][m])
    except EOFError:
        break
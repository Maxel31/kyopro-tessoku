# 巡回セールスマン問題

# 入力
N = int(input())
X = [None] * N
Y = [None] * N
for i in range(N):
    X[i], Y[i] = map(int, input().split())

# 配列dp の初期化
dp = [[1000000000.0] * N for i in range(2 ** N)]

# 動的計画法

# dp[通った都市][今いる都市]
dp[0][0] = 0
for i in range(2 ** N): # 通った都市をbitで表す．
    for j in range(N):
        if dp[i][j] < 1000000000.0:
            # 都市jからkへ移動
            for k in range(N):
                if(i // (2 ** k)) % 2 == 0:
                    # DIST = 都市j,k間の所要時間
                    DIST = ((1.0*(X[j]-X[k])* (X[j]-X[k]) + 1.0*(Y[j]-Y[k])*(Y[j]-Y[k])) ** 0.5)
                    dp[i + 2 ** k][k] = min(dp[i + 2 ** k][k], dp[i][j] + DIST)
                    
# 出力
print(dp[2 ** N - 1][0])
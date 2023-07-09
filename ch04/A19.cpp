#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// ナップザックDP

ll N, W;
ll w[109], v[109];
ll dp[109][100009]; // 品物1,2,,のうちから重さの合計値がjとなるように選ぶ際の合計価値の最大値

int main(){
    // 入力
    cin >> N >> W;
    for(int i = 1; i <=N ; i++) cin >> w[i] >> v[i];
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= W; j++){
            // 小さい値で初期化
            dp[i][j] = -1'000'000'000'000'000LL;
        }
    }

    // 動的計画法
    dp[0][0] = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 0; j <= W; j++){
            if(j < w[i]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = max(dp[i-1][j], dp[i-1][j-w[i]] + v[i]);
        }
    }

    // 出力
    ll ans = 0;
    for(int j = 0; j <= W; j++){
        ans = max(ans, dp[N][j]); // dp[N][i](i = 1 ~ W)農地の最大値が答え, 重さの合計がちょうどWの時の値が必ず答えになるわけではない
    }
    cout << ans << endl;
    return 0;
}
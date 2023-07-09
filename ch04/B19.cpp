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
        for(int j = 0; j <= 100000; j++){
            // 大きい値で初期化
            dp[i][j] = 1'000'000'000'000'000LL;
        }
    }

    // 動的計画法
    dp[0][0] = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 0; j <= 100000; j++){
            if(j < v[i]) dp[i][j] = dp[i-1][j];
            else dp[i][j] = min(dp[i-1][j], dp[i-1][j-v[i]] + w[i]); // 同価値での重さの最小化を考える
        }
    }

    // 出力
    ll ans = 0;
    for(int j = 0; j <= 100000; j++){
        if(dp[N][j] <= W) ans = j;
    }
    cout << ans << endl;
    return 0;
}
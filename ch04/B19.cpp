#include <bits/stdc++.h>
using namespace std;
# define rep(i, n) for(int i =1; i <= (n); ++i)
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL << 60;

ll N, W, w[109], v[109], dp[109][100009];

int main(){
    // 入力
    cin >> N >> W;
    rep(i, N) cin >> w[i] >> v[i];

    // dp[i][j]: 品物1 ~ i から，価値の合計がjとなるように選ぶことを考える．
    // このときの重さの総和の最小値をdp[i][j]とする．

    // 初期化
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= 100000; j++){
            dp[i][j] = 1'000'000'000'000'000'000LL;
        }
    }
    
    // 動的計画法
    dp[0][0] = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 0; j <= 100000; j++){
            if(j < v[i]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = min(dp[i - 1][j], dp[i - 1][j - v[i]] + w[i]);
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

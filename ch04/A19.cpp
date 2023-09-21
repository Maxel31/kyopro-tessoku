#include <bits/stdc++.h>
using namespace std;
# define rep(i, n) for(int i =1; i <= (n); ++i)
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL << 60;

// ナップザックDP
int N, W;
ll w[109], v[109];
ll dp[109][100009];

int main(){
    // 入力
    cin >> N >> W;
    rep(i, N) cin >> w[i] >> v[i];

    // dp[i][j]: 品物1 ~ i から，重さの合計がjとなるように選ぶことを考える．
    // このときの価値の総和の最大値をdp[i][j]とする．

    // 初期化
    for(int i = 0; i <= N; i++){
        for(int j = 0; j <= W; j++){
            dp[i][j] = -1'000'000'000'000'000'000LL;
        }
    }

    // 動的計画法
    dp[0][0] = 0;
    for(int i = 1; i <= N; i++){
        for(int j = 0; j <= W; j++){
            if(j < w[i]) dp[i][j] = dp[i - 1][j];
            else dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
        }
    }

    // 出力
    ll ans = 0;
    for(int j = 0; j <= W; j++){
        ans = max(ans, dp[N][j]);
    }
    cout << ans << endl;
    return 0;
}
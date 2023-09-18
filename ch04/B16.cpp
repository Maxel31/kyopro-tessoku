#include <bits/stdc++.h>
using namespace std;
# define rep(i, n) for(int i =1; i <= (n); ++i)
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL << 60;

int main(){
    // 入力
    int N, h[100009], dp[100009];
    cin >> N;
    rep(i, N) cin >> h[i];

    // 動的計画法
    // dp[i] : 足場iに到達するまでの最小コスト
    dp[1] = 0;
    dp[2] = abs(h[2] - h[1]);
    
    for(int i = 3; i <= N; i++){
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
    }
    
    cout << dp[N] << endl;
    return 0;
}
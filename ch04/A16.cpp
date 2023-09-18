#include <bits/stdc++.h>
using namespace std;
# define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL << 60;

int main(){
    // 入力
    int N, A[100009], B[100009], dp[100009];
    cin >> N;
    for(int i = 2; i <= N; i++) cin >> A[i];
    for(int i = 3; i <= N; i++) cin >> B[i];

    // 動的計画法
    // dp[i] : 部屋iに到達するまでの最小時間
    dp[1] = 0;
    dp[2] = A[2];
    for(int i = 3; i <= N; i++){
        dp[i] = min(dp[i - 1] + A[i], dp[i - 2] + B[i]);
    }
    cout << dp[N] << endl;
    return 0;
}
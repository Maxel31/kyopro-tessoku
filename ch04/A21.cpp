#include <bits/stdc++.h>
using namespace std;
# define rep(i, n) for(int i =1; i <= (n); ++i)
using ll = long long;
// using P = pair<int, int>;
const long long INF = 1LL << 60;

// 区間dp
int N, P[2009], A[2009], dp[2009][2009];

int main(){
    // 入力
    cin >> N;
    rep(i, N) cin >> P[i] >> A[i];

    // ブロックの状態を左端の番号l, 右端の番号rで管理する．

    // 動的計画法
    dp[1][N] = 0; // dp で点数を管理する．
    for(int LEN = N-2; LEN >= 0; LEN--){
        for(int l = 1; l <= N - LEN; l++){
            int r = l + LEN;

            // score1 の値: l-1番目のブロックを取り除いたときの点数
            int score1 = 0;
            if(l <= P[l-1] && P[l-1] <= r) score1 = A[l-1];

            // score2 の値: r+1番目のブロックを取り除いたときの点数
            int score2 = 0;
            if(l <= P[r+1] && P[r+1] <= r) score2 = A[r+1];

            if(l == 1){
                dp[l][r] = dp[l][r+1] + score2;
            }
            else if(r == N){
                dp[l][r] = dp[l-1][r] + score1;
            }
            else{
                dp[l][r] = max(dp[l-1][r] + score1, dp[l][r+1] + score2);
            }
        }
    }

    // 出力
    int ans = 0;
    rep(i, N)  ans = max(ans, dp[i][i]);
    cout << ans << endl;
    return 0;
}



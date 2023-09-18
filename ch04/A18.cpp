#include <bits/stdc++.h>
using namespace std;
# define rep(i, n) for(int i =1; i <= (n); ++i)
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL << 60;

int main(){
    // 入力
    int N, S, A[10009];
    bool dp[69][10009];
    cin >> N >> S;
    rep(i, N) cin >> A[i];

    // 部分和問題 
    // dp[i][j]: i枚目までのカードを使って，合計をjにできるか

    // 初期化
    rep(i, N) rep(j, S) dp[i][j] = false;
    dp[0][0] = true;

    // 動的計画法
    for(int i = 1; i <= N; i++){
        for(int j = 0; j <= S; j++){
            if(j < A[i]){
                if(dp[i - 1][j]) dp[i][j] = true; // i枚目を使わない
                else dp[i][j] = false;
            }
            else{
                if(dp[i - 1][j] || dp[i - 1][j - A[i]]) dp[i][j] = true; // i枚目を使わない or i枚目を使う
                else dp[i][j] = false;
            }
        }
    }

    // 出力
    if(dp[N][S]) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
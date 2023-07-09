#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
int dp[1009][1009]; // 文字列SのL番目からR番目までの部分における最長回文の長さ
string S;

int main(){
    // 入力
    cin >> N;
    cin >> S;

    // 動的計画法 (初期状態)
    for(int i = 0; i < N; i++) dp[i][i] = 1;
    for(int i = 0; i < N - 1; i++){
        if(S[i] == S[i+1]) dp[i][i+1] = 2;
        else dp[i][i+1] = 1;
    }
    // 動的計画法(状態遷移)
    for(int LEN = 2; LEN <= N - 1; LEN++){
        for(int L = 0; L + LEN < N; L++){
            int R = L + LEN;
            if(S[L] == S[R]){
                dp[L][R] = max({dp[L][R-1], dp[L+1][R], dp[L+1][R-1] + 2});
            }
            else {
                dp[L][R] = max({dp[L][R-1], dp[L+1][R]});
            }
        }
    }

    // 出力
    cout << dp[0][N-1] << endl;
    return 0;
}
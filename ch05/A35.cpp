#include <bits/stdc++.h>    
using namespace std;
using ll = long long;

int N, A[2009];
int dp[2009][2009]; // ゲームが状態(i,j)まで進行した際の想定スコア

int main(){
    // 入力
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> A[i];

    // 初期化
    for(int j = 1; j <= N; j++) dp[N][j] = A[j];

    // 操作(ゴールから逆算する)
    for(int i = N-1; i >= 1; i--){
        for(int j = 1; j <= i; j++){
            if(i % 2 == 1) dp[i][j] = max(dp[i+1][j], dp[i+1][j+1]);
            else dp[i][j] = min(dp[i+1][j], dp[i+1][j+1]);
        }
    }

    // 出力
    cout << dp[1][1] << endl;
    return 0;
}
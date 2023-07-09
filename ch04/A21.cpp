#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N, P[2009], A[2009];
int dp[2009][2009];

int main(){
    // 入力
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> P[i] >> A[i];

    // 動的計画法
    dp[1][N] = 0;
    for(int LEN = N - 2; LEN >= 0; LEN--){
        for(int L = 1; L + LEN <= N; L++){
            int R = L + LEN;

            // Score1(左端を取り除く時)
            int Score1 = 0;
            if(L <= P[L-1] && P[L-1] <= R) Score1 = A[L-1];

            // Score2(右端を取り除く時)
            int Score2 = 0;
            if(L <= P[R+1] && P[R+1] <= R) Score2 = A[R+1];

            // dp[L][R]
            if(L == 1){
                dp[L][R] = dp[L][R+1] + Score2;
            }
            else if(R == N){
                dp[L][R] = dp[L-1][R] + Score1;
            }
            else{
                dp[L][R] = max(dp[L][R+1] + Score2, dp[L-1][R] + Score1);
            }
        }
    }

    // 出力
    int ans = 0;
    for(int i = 1; i <= N; i++){
        ans = max(ans, dp[i][i]);
    }
    cout << ans << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL<<60;

int N, Q, A[100009], X[100009], Y[100009];
// dp[i][j]: 穴jにいた2^i日後の場所
// 任意の日数後の場所は2^i日後の場所の組み合わせで表現される
int dp[32][100009];

int main(){
    // 入力
    cin >> N >> Q;
    for(int i=1; i<=N; i++) cin >> A[i];
    for(int i=1; i<=Q; i++) cin >> X[i] >> Y[i];

    // 初期値
    for(int i=1; i<=N; i++) dp[0][i] = A[i];
    // 前処理
    for(int d=1; d<=29; d++){
        for(int i=1; i<=N; i++){
            dp[d][i] = dp[d-1][dp[d-1][i]];
        }
    }

    // 処理
    for(int j=1;j<=Q; j++){
        int CurrentPlace = X[j];
        for(int d=29; d>=0; d--){
            if(Y[j] / (1<<d) % 2 != 0){
                CurrentPlace = dp[d][CurrentPlace];
            }
        }
        cout << CurrentPlace << endl;
    }

}
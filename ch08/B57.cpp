#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL<<60;

ll N, K;
ll dp[32][300009]; // dp[i][j]: 数字jから2^i回操作を行った後の数字

int main(){
    // 入力
    cin >> N >> K;

    // 処理1回分
    for(int i = 1; i <= N; i++){
        string str = to_string(i);
        dp[0][i] = i;
        for(int j = 0; j < str.size(); j++){
            dp[0][i] -= str[j] - '0';
        }
    }

    // 漸化式, あらかじめ配列に計算結果を入れておく
    for(int d = 1; d <= 29; d++){
        for(int i = 1; i <= N; i++){
            dp[d][i] = dp[d-1][dp[d-1][i]];
        }
    }

    // Nこの数字それぞれについて
    // K回の操作を行う(2の累乗の合計で表される)
    for(int i = 1; i <= N; i++){
        int CurrentNum = i;
        for(int d = 29; d >= 0; d--){
            if(K / (1<<d) % 2 != 0){
                // bit が立っているとこだけ踏んでいく
                CurrentNum = dp[d][CurrentNum];
            }
        }
        cout << CurrentNum << endl;
    }
    return 0;
}
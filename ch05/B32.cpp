#include <bits/stdc++.h>    
using namespace std;
using ll = long long;

int main(){
    // 入力
    int N,K;
    cin >> N >> K;
    int a[109];
    for(int i = 1; i <= K; i++) cin >> a[i];

    // 負け状態に遷移できるか
    bool dp[100009];
    // 石数0状態への遷移も考える
    for(int i = 0; i <= N; i++){
        dp[i] = false;
        for(int j = 1; j <= K; j++){
            if(i >=  a[j] && dp[i - a[j]] == false){
                dp[i] = true;
            }
        }
    }

    if(dp[N]) cout << "First" << endl;
    else cout << "Second" << endl;
    return 0;
}
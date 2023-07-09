#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    // 入力
    int N, A, B;
    cin >> N >> A >> B;

    // 勝ちの条件: 負け状態に遷移する行動が存在する．
    // 次ターンに相手が負ける．

    // N以下の各石数で，先手必勝 or 後手必勝か記録する
    bool dp[100009];
    for(int i = 1; i <= N; i++){
        // 負け状態に遷移可能
        if(i >= A && dp[i - A] == false) dp[i] = true;
        else if(i >= B && dp[i - B] == false) dp[i] = true;
        // 遷移不可能
        else dp[i] = false;
    }

    if(dp[N]) cout << "First" << endl;
    else cout << "Second" << endl;
    return 0;
}
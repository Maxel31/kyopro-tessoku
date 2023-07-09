#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// 部分和問題
int N, S;
int A[69];
bool dp[69][10009]; 
// dp[i][j] := i番目までの整数の中からいくつか選んで総和をjにすることができるかどうか

int main(){
    // 入力
    cin >> N >> S;
    for (int i = 1; i <= N; i++) cin >> A[i];

    // 動的計画法(i = 0)
    dp[0][0] = true;
    for(int i = 1; i <= S; i++) dp[0][i] = false;

    // 動的計画法(i = 1 ~ N)
    for(int i = 1; i <= N; i++){
        for(int j = 0; j <= S; j++){
            if(j < A[i]){
                if(dp[i-1][j] == true) dp[i][j] = true;
                else dp[i][j] = false;
            }
            else{
                if(dp[i-1][j] == true || dp[i-1][j-A[i]] == true) dp[i][j] = true;
                else dp[i][j] = false;
            }
        }
    }

    // 出力1
    if(dp[N][S] == false){
        cout << -1 << endl;
        return 0;
    }

    // 経路の復元
    int Place = S;
    vector<int> ans;
    for(int i = N; i >= 1; i--){
        if(dp[i-1][Place] == true) continue;
        else{
            ans.push_back(i);
            Place -= A[i];
        }
    }
    reverse(ans.begin(), ans.end());

    // 出力2
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
int A[100009], B[100009], dp[100009];

int main(){
    //入力
    cin >> N;
    for(int i = 2; i <= N; i++) cin >> A[i];
    for(int i = 3; i <= N; i++) cin >> B[i];

    // 動的計画法
    dp[1] = 0;
    dp[2] = A[2];
    for(int i = 3; i <= N; i++){
        dp[i] = min(dp[i - 1] + A[i], dp[i - 2] + B[i]);
    }

    // 答えの復元
    int Place = N;
    vector<int> ans;
    while(Place > 0){
        ans.push_back(Place);
        if(dp[Place - 1] + A[Place] == dp[Place]) Place--;
        else Place -= 2;
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}
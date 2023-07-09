#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
int h[100009], dp[100009];

int main(){
    // 入力
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> h[i];

    // 動的計画法
    dp[1] = 0;
    dp[2] = abs(h[2] - h[1]);
    for(int i = 3; i <= N; i++){
        dp[i] = min(dp[i - 1] + abs(h[i] - h[i - 1]), dp[i - 2] + abs(h[i] - h[i - 2]));
    }

    // 経路の復元
    int Place = N;
    vector<int> ans;
    while(Place > 0){
        ans.push_back(Place);
        if(dp[Place - 1] + abs(h[Place] - h[Place - 1]) == dp[Place]) Place--;
        else Place -= 2;
    }
    reverse(ans.begin(), ans.end());
    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}
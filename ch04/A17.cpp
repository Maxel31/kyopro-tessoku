#include <bits/stdc++.h>
using namespace std;
# define rep(i, n) for(int i =1; i <= (n); ++i)
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL << 60;

int main(){
    // 入力
    int N, A[100009], B[100009], dp[100009];
    cin >> N;
    for(int i = 2; i <= N; i++) cin >> A[i];
    for(int i = 3; i <= N; i++) cin >> B[i];

    // 動的計画法
    // dp[i] : 足場iに到達するまでの最小コスト
    dp[1] = 0;
    dp[2] = A[2];
    for(int i = 3; i <= N; i++){
        dp[i] = min(dp[i - 1] + A[i], dp[i - 2] + B[i]);
    }

    // ゴールから通った経路を復元
    vector<int> path;
    int now = N;
    while(now != 1){
        path.push_back(now);
        if(dp[now - 1] + A[now] == dp[now]) now--;
        else now -= 2;
    }
    path.push_back(1);
    reverse(path.begin(), path.end());

    // 出力
    cout << path.size() << endl;
    for(int i = 0; i < path.size(); i++){
        cout << path[i] << " ";
    }
    cout << endl;
    return 0;
}
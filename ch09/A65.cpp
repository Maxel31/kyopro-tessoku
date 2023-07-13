#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL<<30;

int N, A[100009];
vector<int> G[100009]; // 上司，部下のグラフ

int main(){
    // 入力
    cin >> N;
    for(int i = 2; i <= N; i++){
        cin >> A[i];
        G[A[i]].push_back(i);
    }

    // 動的計画法を使って，再帰的に計算
    int dp[100009]; // dp[i] := i番目の人の部下の数
    
    // 1頂点に複数ノードがある場合あり
    for(int i = N; i >= 1; i--){
        dp[i] = 0;
        for(int j = 0; j < G[i].size(); j++){
            dp[i] += dp[G[i][j]]+1; // 直下の分+1
        }
    }

    // 出力
    for(int i = 1; i <= N; i++){
        cout << dp[i] << " ";
    }
    cout << endl;
}
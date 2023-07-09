#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL<<60;

int main(){
    // 入力
    int N, M, A[100009], B[100009];
    cin >> N >> M;
    for(int i=1; i<=M; i++){
        cin >> A[i] >> B[i];
    }

    // 隣接リスト
    vector<int> G[100009];
    for(int i=1; i<=M; i++){
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }

    // 最も友達の多い生徒を求める
    int ans;
    int max_num = 0;
    for(int i=1; i<=N; i++){
        if(max_num < G[i].size()){
            max_num = G[i].size();
            ans = i;
        }
    }
    cout << ans << endl;
    return 0;
}
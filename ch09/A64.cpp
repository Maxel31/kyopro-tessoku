#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL<<30;

// 入力
int N, M;
int A[100009], B[100009], C[100009];
int dist[100009]; //頂点1からの距離
vector<P> G[100009]; //隣接リスト

// ダイクストラ法
ll cur[100009]; //頂点iへの距離の暫定値
bool kakutei[100009]; //頂点iが確定済みかどうか
priority_queue<P, vector<P>, greater<P>> Q; //頂点iに最後に訪れた時刻, 頂点i

int main(){
    // 入力
    cin >> N >> M;
    for(int i = 1; i <= M; i++){
        cin >> A[i] >> B[i] >> C[i];
        G[A[i]].push_back(P(B[i], C[i]));
        G[B[i]].push_back(P(A[i], C[i]));
    }

    // 配列の初期化
    for(int i = 1; i <= N; i++) kakutei[i] = false;
    for(int i = 1; i <= N; i++) cur[i] = INF;

    // スタート地点を設定
    cur[1] = 0;
    Q.push(make_pair(cur[1], 1));

    // ダイクストラ法
    while(!Q.empty()){
        int pos = Q.top().second; Q.pop();
        if(kakutei[pos]) continue;
        kakutei[pos] = true;
        for(P to : G[pos]){
            int nex = to.first;
            int cost = to.second;
            if(cur[nex] > cur[pos] + cost){
                cur[nex] = cur[pos] + cost;
                Q.push(make_pair(cur[nex], nex));
            }
        }
    }

    // 出力
    for(int i = 1; i <= N; i++){
        if(cur[i] == INF) cout << -1 << endl;
        else cout << cur[i] << endl;
    }
    return 0;
}
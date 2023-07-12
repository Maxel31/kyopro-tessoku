#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL<<60;

int N, M, A[100009], B[100009];
int dist[100009]; //頂点1からの距離 
vector<int> G[100009]; //隣接リスト
queue<int> Q;

int main(){
    // 入力
    cin >> N >> M;
    for(int i = 1; i <= M; i++){
        cin >> A[i] >> B[i];
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }

    // 幅優先探索
    for(int i = 1; i <= N; i++) dist[i] = -1;
    Q.push(1);
    dist[1] = 0;

    // 処理
    while(!Q.empty()){
        int pos = Q.front(); Q.pop();
        for(int to : G[pos]){
            if(dist[to] != -1) continue;
            dist[to] = dist[pos] + 1;
            Q.push(to);
        }
    }

    // 出力
    for(int i = 1; i <= N; i++){
        cout << dist[i] << endl;
    }
    return 0;
}


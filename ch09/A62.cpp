#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL<<60;

int N, M, A[100009], B[100009];
vector<int> G[100009];
bool visited[100009];

// 深さ優先探索
void dfs(int v){
    visited[v] = true;
    for(int nv : G[v]){
        if(visited[nv]) continue;
        dfs(nv);
    }
}

int main(){
    // 入力
    cin >> N >> M;
    for(int i=1; i<=M; i++){
        cin >> A[i] >> B[i];
    }
    
    // 隣接リスト
    for(int i=1; i<=M; i++){
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }

    // DFS
    for(int i = 1; i <= N; i++){
        visited[i] = false;
    }
    dfs(1);

    // 出力
    string ans = "The graph is connected.";
    for(int i = 1; i <= N; i++){
        if(!visited[i]){
            ans = "The graph is not connected.";
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
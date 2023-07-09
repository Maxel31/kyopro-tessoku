#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL<<60;

int N, M, A[100009], B[100009];
vector<int> G[100009];
bool visited[100009];

// 深さ優先探索
vector<int> Path, ans;
void dfs_path(int pos){
    if(pos == N){
        ans = Path;
        return;
    }

    visited[pos] = true;
    for(int nv : G[pos]){
        if(visited[nv]) continue;
        Path.push_back(nv);
        dfs_path(nv);
        Path.pop_back();
    }
    return;
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
    Path.push_back(1);
    dfs_path(1);

    // 出力
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}

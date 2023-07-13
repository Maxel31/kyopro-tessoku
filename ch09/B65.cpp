#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const ll INF = 1LL<<30;


// 入力
int N, T;
int A[100009], B[100009];
int ans[100009];

vector<int> G[100009]; // 上司，部下のグラフ
bool visited[100009];

// 深さ優先探索, 社員の階級を返す
int dfs(int pos){
    visited[pos] = true;
    ans[pos] = 0;
    for(int nv = 0; nv < G[pos].size(); nv++){
        int nex = G[pos][nv];
        if(!visited[nex]) {
            int ret = dfs(nex); // 再帰計算, 社員posを根として繰り返す
            ans[pos] = max(ans[pos], ret+1);
        }
    }
    return ans[pos];
}

int main(){
    // 入力
    cin >> N >> T;
    for(int i = 1; i <= N-1; i++){
        cin >> A[i] >> B[i];
        G[A[i]].push_back(B[i]);
        G[B[i]].push_back(A[i]);
    }       

    // 上司の数を求める
    dfs(T); // 根から始める

    // 出力
    for(int i = 1; i <= N; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
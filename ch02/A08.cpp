#include <bits/stdc++.h>
using namespace std;
# define rep(i, n) for(int i = 1; i <= (n); ++i)
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL << 60;

int H, W, Q;
int X[1509][1509];
int A[100009], B[100009], C[100009], D[100009];
// 各マスの累積和 (二次元累積和)
int S[1509][1509];

int main(){
    // 入力
    cin >> H >> W;
    rep(i, H) rep(j, W) cin >> X[i][j];
    cin >> Q;
    rep(i, Q) cin >> A[i] >> B[i] >> C[i] >> D[i];

    // 初期化
    for(int i = 0; i <= H; i++){
        for(int j = 0; j <= W; j++){
            S[i][j] = 0;
        }
    }

    // 横方向の累積和
    rep(i, H) rep(j, W) S[i][j] = S[i][j-1] + X[i][j];
    // 縦方向の累積和
    rep(j, W) rep(i, H) S[i][j] += S[i-1][j];

    // クエリの処理
    rep(i, Q){
        int ans = 0;
        ans += S[C[i]][D[i]];
        ans -= S[A[i]-1][D[i]];
        ans -= S[C[i]][B[i]-1];
        ans += S[A[i]-1][B[i]-1];
        cout << ans << endl;
    }

}
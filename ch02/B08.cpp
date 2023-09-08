#include <bits/stdc++.h>
using namespace std;
# define rep(i, n) for(int i = 1; i <= (n); ++i)
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL << 60;

int N, Q;
int X[100009], Y[100009], a[100009], b[100009], c[100009], d[100009];
// 各座標に何個点があるか
int cnt[1509][1509];

// 各マスの累積和 (二次元累積和)
int S[1509][1509];

int main(){
    // 入力
    cin >> N;
    rep(i, N) cin >> X[i] >> Y[i];
    cin >> Q;
    rep(i, Q) cin >> a[i] >> b[i] >> c[i] >> d[i];

    // 初期化
    for(int i = 0; i <= 1500; i++){
        for(int j = 0; j <= 1500; j++){
            cnt[i][j] = 0;
            S[i][j] = 0;
        }
    }

    // 各座標に何個点があるか
    rep(i, N) cnt[X[i]][Y[i]]++;

    // 二次元累積和を取る
    // 横方向の累積和
    rep(i, 1500) rep(j, 1500) S[i][j] = S[i][j-1] + cnt[i][j];
    // 縦方向の累積和
    rep(j, 1500) rep(i, 1500) S[i][j] += S[i-1][j];

    // クエリに答える
    rep(i, Q){
        int ans = 0;
        ans += S[c[i]][d[i]];
        ans -= S[a[i]-1][d[i]];
        ans -= S[c[i]][b[i]-1];
        ans += S[a[i]-1][b[i]-1];
        cout << ans << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
# define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL << 60;

int main(){
    // 入力
    int N, Q;
    int A[100009], L[100009], R[100009];
    cin >> N >> Q;
    rep(i, N) cin >> A[i];
    rep(i, Q) cin >> L[i] >> R[i];

    // 累積和
    ll S[100009];
    S[0] = 0;
    rep(i, N) S[i+1] = S[i] + A[i];

    // クエリ処理
    ll ans[100009];
    rep(i, Q) ans[i] = S[R[i]] - S[L[i]-1];

    // 出力
    rep(i, Q) cout << ans[i] << endl;   
    return 0;
}
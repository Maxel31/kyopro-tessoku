#include <bits/stdc++.h>
using namespace std;
# define rep(i, n) for(int i = 1; i <= (n); ++i)
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL << 60;

int H, W, N;
int A[100009], B[100009], C[100009], D[100009];
int S[1509][1509], T[1509][1509];

int main(){
    cin >> H >> W >> N;
    rep(i, N) cin >> A[i] >> B[i] >> C[i] >> D[i];

    // 各日について加算
    rep(i, N){
        S[A[i]][B[i]]++;
        S[A[i]][D[i]+1]--;
        S[C[i]+1][B[i]]--;
        S[C[i]+1][D[i]+1]++;
    }

    // 二次元累積和
    // 初期化
    for(int i = 0; i <= H; i++){
        for(int j = 0; j <= W; j++){
            T[i][j] = 0;
        }
    }

    // 横方向の累積和
    rep(i, H) rep(j, W) T[i][j] = T[i][j-1] + S[i][j];
    // 縦方向の累積和
    rep(j, W) rep(i, H) T[i][j] += T[i-1][j];

    // 出力
    rep(i, H){
        rep(j, W){
            cout << T[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
# define rep(i, n) for(int i = 1; i <= (n); ++i)
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL << 60;

int N;
int A[100009], B[100009], C[100009], D[100009];
int S[1509][1509];
int cnt = 0;

int main(){
    // 入力
    cin >> N;
    rep(i, N) cin >> A[i] >> B[i] >> C[i] >> D[i];

    for(int i = 0; i <= 1500; i++){
        for(int j = 0; j <= 1500; j++){
            S[i][j] = 0;
        }
    }

    // 各マスについて加算
    rep(i, N){
        S[A[i]][B[i]]++;
        S[A[i]][D[i]]--;
        S[C[i]][B[i]]--;
        S[C[i]][D[i]]++;
    }

    // 二次元累積和

    // 横方向の累積和
    for(int i = 0; i <= 1500; i++) for(int j = 1; j <= 1500; j++) S[i][j] = S[i][j-1] + S[i][j];
    // 縦方向の累積和
    for(int i = 1; i <= 1500; i++) for(int j = 0; j <= 1500; j++) S[i][j] += S[i-1][j];

    // 各マスについて一枚以上紙が置かれているか
    for(int i = 0; i <= 1500; i++) for(int j = 0; j <= 1500; j++){
        if(S[i][j] >= 1) cnt++;
    }

    cout << cnt << endl;
    return 0;

}
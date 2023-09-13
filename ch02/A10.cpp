#include <bits/stdc++.h>
using namespace std;
# define rep(i, n) for(int i = 1; i <= (n); ++i)
using ll = long long;
const long long INF = 1LL << 60;

int N, D;
int A[100009], L[100009], R[100009];
int P[100009], Q[100009];

int main(){
    // 入力
    int N;
    cin >> N;
    rep(i, N) cin >> A[i];
    cin >> D;
    rep(i, D) cin >> L[i] >> R[i];

    // 累積和
    // P[i] : 1号室からi号室までの最大人数
    // Q[i] : i 号室から N 号室までの最大人数
    P[1] = A[1];
    for(int i = 2; i <= N; i++) P[i] = max(P[i-1], A[i]);
    Q[N] = A[N];
    for(int i = N-1; i >= 1; i--) Q[i] = max(Q[i+1], A[i]);

    // それぞれの日について答えを求める
    rep(i, D){
        int ans = max(P[L[i]-1], Q[R[i]+1]);
        cout << ans << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
# define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL << 60;

int main(){
    // 入力
    int D, N;
    int L[100009], R[100009];
    cin >> D >> N;
    rep(i, N) cin >> L[i] >> R[i];

    // 各日の参加者数の前日比
    int A[100009];
    rep(i, D) A[i] = 0;
    rep(i, N){
        A[L[i]]++;
        A[R[i]+1]--;
    }

    // 各日の参加数
    int B[100009];
    B[0] = A[0];
    rep(i, D) B[i+1] = B[i] + A[i+1];

    // 出力数
    rep(i, D){
        cout << B[i+1] << endl;
    }
    return 0;
}
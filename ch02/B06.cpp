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
    cin >> N;
    rep(i, N) cin >> A[i];
    cin >> Q;
    rep(i, Q) cin >> L[i] >> R[i];

    // 累積和
    int atari[100009], hazure[100009];
    atari[0] = 0; hazure[0] = 0;
    rep(i, N){
        if(A[i] == 1){
            atari[i+1] = atari[i] + 1;
            hazure[i+1] = hazure[i];
        }else{
            atari[i+1] = atari[i];
            hazure[i+1] = hazure[i] + 1;
        }
    }

    // クエリ処理
    rep(i, Q){
        if(atari[R[i]] - atari[L[i]-1] > hazure[R[i]] - hazure[L[i]-1]){
            cout << "win" << endl;
        }
        else if(atari[R[i]] - atari[L[i]-1] < hazure[R[i]] - hazure[L[i]-1]){
            cout << "lose" << endl;
        }
        else{
            cout << "draw" << endl;
        }
    }
    return 0;
}
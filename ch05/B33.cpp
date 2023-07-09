#include <bits/stdc++.h>    
using namespace std;
using ll = long long;

int main(){
    // 入力
    ll N, H, W;
    cin >> N >> H >> W;
    ll A[100009], B[100009];
    for(int i = 1; i <= N; i++) cin >> A[i] >> B[i];

    // 二ムに問題を置き換える
    ll C[200009];
    for(int i = 1; i <= N; i++){
        C[i] = A[i] - 1;
        C[i+N] = B[i] - 1;
    }

    // 以下二ムの問題に帰着させるn
    ll XOR_Sum = C[1];
    for(ll i = 2; i <= 2 * N; i++) XOR_Sum ^= C[i];

    // 出力
    if(XOR_Sum != 0) cout << "First" << endl;
    else cout << "Second" << endl;
    return 0;
}
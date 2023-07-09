#include <bits/stdc++.h>    
using namespace std;
using ll = long long;

int N, X, Y;
int A[100009];
int Grundy[100009];

int main(){
    // 入力
    cin >> N >> X >> Y;
    for(int i=0; i<N; ++i) cin >> A[i];

    // Grundy数を計算
    // Transit[i] Grundy数がiとなるような繊維が出来るか

    for(int i = 0; i <= 100000; i++){
        bool Transit[3] = {false, false, false};
        if(i >= X) Transit[Grundy[i - X]] = true;
        if(i >= Y) Transit[Grundy[i - Y]] = true;
        if(Transit[0] == false) Grundy[i] = 0;
        else if(Transit[1] == false) Grundy[i] = 1;
        else Grundy[i] = 2;
    }

    // 出力
    int XOR_Sum = 0;
    for(int i = 1; i <= N; i++) XOR_Sum ^= Grundy[A[i - 1]];
    if(XOR_Sum != 0) cout << "First" << endl;
    else cout << "Second" << endl;
    return 0;
}

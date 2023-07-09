#include <bits/stdc++.h>    
using namespace std;
using ll = long long;

int main(){
    // 入力
    int N;
    ll A[100009];
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> A[i];

    // 二ムの勝利条件
    // 二ム和を求める
    int XOR_Sum = A[1];
    for(int i = 2; i <= N; i++) XOR_Sum ^= A[i];

    // 出力
    if(XOR_Sum != 0) cout << "First" << endl;
    else cout << "Second" << endl;
}
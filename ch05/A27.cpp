#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int GCD(int a, int b){
    while(a >= 1 && b >= 1){
        if(a >= b) a %= b;
        else b %= a;
    }
    if(a == 0) return b;
    else return a;
}

int main(){
    int A, B;
    cin >> A >> B;
    // AとBの最大公約数を求める
    // ユークリッドの互除法
    cout << GCD(A, B) << endl;
    return 0;
}
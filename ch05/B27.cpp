#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int GCD(ll a, ll b){
    while(a >= 1 && b >= 1){
        if(a >= b) a %= b;
        else b %= a;
    }
    if(a == 0) return b;
    else return a;
}

int main(){
    ll A, B;
    cin >> A >> B;
    // A, Bの最小公倍数を求める
    cout << A * (B / GCD(A, B)) << endl;
    return 0;
}
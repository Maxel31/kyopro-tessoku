#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll m = 1000000007;

// aのb乗をmで割った余りを返す関数
ll pow(ll a, ll b, ll m){
    ll p = a,ans = 1;
    for(int i = 0; i < 30; i++){
        int wari = (1 << i);
        if((b / wari) % 2 == 1){
            ans = (ans * p) % m;
        }
        p = (p * p) % m;
    }
    return ans;
}

// a / b を mで割った余りを返す関数
ll div(ll a, ll b, ll m){
    return (a * pow(b, m - 2, m)) % m;
}

int main(){
    // 入力
    ll H, W;
    cin >> H >> W;

    // 求める値は(H + W - 2) C (H - 1)
    ll n = H + W - 2;
    ll r = H - 1;

    if(n == 0 || r == 0){
        cout << 1 << endl;
        return 0;
    }

    // n! を m で割った余り
    ll a = 1;
    for(int i = 1; i <= n; i++){
        a = (a * i) % m;
    }

    // r! * (n-r)! を m で割った余り
    ll b = 1;
    for(int i = 1; i <= r; i++){
        b = (b * i) % m;
    }
    for(int i = 1; i <= n - r; i++){
        b = (b * i) % m;
    }

    // 答えを求める
    cout << div(a, b, m) << endl;
    return 0;
}

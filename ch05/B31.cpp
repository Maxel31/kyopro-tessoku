#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll N;
    cin >> N;

    ll a = N / 3;
    ll b = N / 5;
    ll c = N / 7;
    ll d = N / 15;
    ll e = N / 21;
    ll f = N / 35;
    ll g = N / 105;

    ll ans = a + b + c - d - e - f + g;

    cout << ans << endl;
    return 0;
}
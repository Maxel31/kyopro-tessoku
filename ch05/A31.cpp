#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    ll N;
    cin >> N;

    ll a = N / 3;
    ll b = N / 5;
    ll c = N / 15;

    ll ans = a + b - c;

    cout << ans << endl;
    return 0;
}
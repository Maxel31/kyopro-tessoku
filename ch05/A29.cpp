#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll a, b, m = 1000000007;

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

int main(){
    cin >> a >> b;
    cout << pow(a, b, m) << endl;
    return 0;
}
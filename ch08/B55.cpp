#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL<<60;

ll Q, query[100009], x[100009];

set<ll> st1, st2;
ll GetDown(ll r){
    auto itr = st2.lower_bound(-r);
    if(itr == st2.end()) return -INF;
    return -(*itr);
}

ll GetUp(ll l){
    auto itr = st1.lower_bound(l);
    if(itr == st1.end()) return INF;
    return *itr;
}



int main(){
    // 入力
    cin >> Q;
    for(ll i = 1; i <= Q; i++) cin >> query[i] >> x[i];
    
    //  処理
    for(ll i = 1; i <= Q; i++){
        if(query[i] == 1){
            st1.insert(x[i]);
            st2.insert(-x[i]);
        }
        if(query[i] == 2){
            ll v1 = GetDown(x[i]);
            ll v2 = GetUp(x[i]);
            ll ans = min(x[i] - v1, v2 - x[i]);
            if(ans > INF/10) cout << -1 << endl;
            else cout << ans << endl;
        }
    }
    return 0;
}
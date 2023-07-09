#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL<<60;

ll N, Q;
string S;
ll a[200009], b[200009], c[200009], d[200009];

ll MOD = 2147483647;
ll T[200009], H[200009];
ll Power100[200009];

// S[l, r] のハッシュ値を計算する関数
ll Hash_Value(ll l, ll r){
    ll val = H[r] - (H[l-1] * Power100[r-l+1] % MOD);
    if(val < 0) val += MOD;
    return val;
}

int main(){
    // 入力
    cin >> N >> Q >> S;
    for(int i = 1; i <= Q; i++) cin >> a[i] >> b[i] >> c[i] >> d[i];

    // 文字列を数値に変換
    for(int i = 1; i <= N; i++) T[i] = (S[i-1] - 'a') + 1;

    // 100のn乗
    Power100[0] = 1;
    for(int i = 1; i <= N; i++) Power100[i] = Power100[i-1] * 100LL % MOD;

    // ハッシュ値を計算
    H[0] = 0;
    for(int i = 1; i <= N; i++) H[i] = (H[i-1] * 100LL + T[i]) % MOD;

    // 処理
    for(int i = 1; i <= Q; i++){
        ll Hash1 = Hash_Value(a[i], b[i]);
        ll Hash2 = Hash_Value(c[i], d[i]);
        if(Hash1 == Hash2) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}
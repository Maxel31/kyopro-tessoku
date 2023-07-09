#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL<<60;

int main(){
    // 入力
    int N;
    cin >> N;
    int A[100009];
    for(int i = 1; i <= N; i++){
        cin >> A[i];
    }

    // 連想配列で処理
    map<int, int> mp;
    ll ans = 0;
    for(int i = 1; i <= N; i++){
        ans += mp[A[i]];
        mp[A[i]]++;
    }

    // 出力
    cout << ans << endl;
    return 0;
}
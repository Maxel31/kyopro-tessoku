#include <bits/stdc++.h>
using namespace std;
# define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL << 60;

int main(){
    // 入力
    int T, N;
    int L[500009], R[500009];
    cin >> T >> N;
    rep(i, N) cin >> L[i] >> R[i];

    // 各日の参加者数の前日比
    int diff[500009];
    rep(i, T) diff[i] = 0;
    rep(i, N){
        diff[L[i]]++;
        diff[R[i]]--;
    }

    // 各日の参加数
    int sum[500009];
    sum[0] = diff[0];
    rep(i, T) sum[i+1] = sum[i] + diff[i+1];

    // 出力
    rep(i, T){
        cout << sum[i] << endl;
    }
    return 0;
}
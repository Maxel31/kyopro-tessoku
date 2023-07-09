#include <bits/stdc++.h>    
using namespace std;
using ll = long long;

int D, N;
int L[10009], R[10009], H[10009], LIM[10009]; //LIM[d]: d日目の労働時間の上限値

int main(){
    // 入力
    cin >> D >> N;
    for(int i = 1; i <= N; i++) cin >> L[i] >> R[i] >> H[i];

    // 配列の初期化
    for(int i = 1; i <= D; i++) LIM[i] = 24;

    // 上限値を求める
    for(int i = 1; i <= N; i++){
        for(int j = L[i]; j <= R[i]; j++) LIM[j] = min(LIM[j], H[i]);
    }

    // 出力
    int ans = 0;
    for(int i = 1; i <= D; i++) ans += LIM[i];
    cout << ans << endl;
    return 0;
}

#include <bits/stdc++.h>    
using namespace std;
using ll = long long;

int N, ret1[1 << 18], ret2[1 << 18];
string S;

int main(){
    // 入力
    cin >> N >> S;

    // 答えを求める
    int streak1 = 1; ret1[0] = 1; // streal1: 「何個Aが連続したか」+ 1
    for(int i = 0; i < N; i++){
        if(S[i] == 'A') streak1++;
        if(S[i] == 'B') streak1 = 1;
        ret1[i + 1] = streak1;
    }

    int streak2 = 1; ret2[N-1] = 1; // streak2: 「何個Bが連続したか」+ 1
    for(int i = N - 2; i >= 0; i--){
        if(S[i] == 'B') streak2++;
        if(S[i] == 'A') streak2 = 1;
        ret2[i] = streak2;
    }

    // 出力
    ll ans = 0;
    for(int i = 0; i < N; i++) ans += max(ret1[i], ret2[i]);
    cout << ans << endl;
    return 0;
}
#include <bits/stdc++.h>    
using namespace std;
using ll = long long;

// 不変量: ON(OFF)になっている電球の個数の偶奇

int main(){
    // 入力
    int N, K;
    cin >> N >> K;;
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        char S;
        cin >> S;
        if(S == '1') cnt++;
    }

    // 不変量に注目する
    if(cnt % 2 == K % 2) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
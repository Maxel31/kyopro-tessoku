#include <bits/stdc++.h>    
using namespace std;
using ll = long long;

int N, A[200009];
ll cnt[109], ans = 0;

int main(){
    // 入力
    cin >> N;
    for(int i = 0; i < N; i++) cin >> A[i];

    // 各長さの棒の個数を数えることで解決
    // 個数を数える
    for(int i = 1; i <= 100; i++) cnt[i] = 0;
    for(int i = 0; i < N; i++) cnt[A[i]]++;

    // 答えを求める
    // nC3 = n * (n-1) * (n-2) / 6
    for(int i = 1; i <= 100; i++){
        ans += cnt[i] *(cnt[i] - 1) * (cnt[i] - 2) / 6;
    }
    cout << ans << endl;
    return 0;
}
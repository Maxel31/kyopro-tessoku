#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
int A[100009], dp[100009];
int LEN = 0, L[100009]; // LEN は L の長さ

// dp[i]: 最後の要素がAiである部分列のう最長のものの長さ
// L[x]: 長さxの部分列の最後の要素として考えられる最小値

int main(){
    // 入力
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> A[i];

    // 動的計画法
    for(int i = 1; i <= N; i++){
        int pos = lower_bound(L + 1, L + LEN + 1, A[i]) - L;
        dp[i] = pos;

        // 配列 L を更新
        L[dp[i]] = A[i];
        if(dp[i] > LEN) LEN++;
    }

    cout << LEN << endl;
    return 0;
}


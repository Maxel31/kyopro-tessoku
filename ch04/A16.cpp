#include <bits/stdc++.h>
using namespace std;
using ll = long long;


int N;
int A[100009], B[100009], ans[100009];
int main(){
    // 入力
    cin >> N;
    for(int i = 2; i <= N; i++) cin >> A[i];
    for(int i = 3; i <= N; i++) cin >> B[i];

    // 動的計画法
    ans[1] = 0;
    ans[2] = A[2];
    for(int i = 3; i <= N; i++){
        ans[i] = min(ans[i - 1] + A[i], ans[i - 2] + B[i]);
    }
    cout << ans[N] << endl;
    return 0;
}
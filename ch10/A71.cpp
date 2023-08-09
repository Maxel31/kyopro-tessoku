#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL<<60;

int main(){
    // 入力
    int N;
    cin >> N;
    int A[69], B[69];
    for(int i = 1; i <= N; i++) cin >> A[i];
    for(int i = 1; i <= N; i++) cin >> B[i];

    // 気温が高い日ほど簡単な宿題をやる
    sort(A + 1, A + N + 1);
    sort(B + 1, B + N + 1, greater<int>());

    int sum = 0;
    for(int i = 1; i <= N; i++){
        sum += A[i] * B[i];
    }
    cout << sum << endl;
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
# define rep(i, n) for(int i = 0; i < (n); ++i)
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL << 60;

int main(){
    ll N, X;
    ll A[100009];
    cin >> N >> X;
    rep(i, N) cin >> A[i];

    cout << lower_bound(A + 1, A + N + 1, X) - A + 1  << endl;
    return 0;
}
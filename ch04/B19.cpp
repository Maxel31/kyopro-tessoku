#include <bits/stdc++.h>
using namespace std;
# define rep(i, n) for(int i =1; i <= (n); ++i)
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL << 60;

int main(){
    // 入力
    int N, W;
    int w[109], v[109], dp[109][109];
    P p[109];
    cin >> N >> W;
    rep(i, N) {
        cin >> w[i] >> v[i];
        p[i] = make_pair(w[i], v[i]);
    }
}
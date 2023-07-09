#include <algorithm>
#include <array>
#include <bitset>
#include <cassert>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <string>
#include <tuple>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>

using namespace std;
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; } // aとbを比較してbの方が大きい場合はaをbで更新する
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; } // aとbを比較してbの方が小さい場合はaをbで更新する

ll N, L;
ll A[200009];
char B[200009];

int main(){
    // 入力
    cin >> N >> L;
    for(int i = 1; i <= N; i++) cin >> A[i] >> B[i];

    // 人を区別しないで考える.
    int ans = 0;
    for(int i = 1; i <= N; i++){
        if(B[i] == 'E'){
            int tmp = L - A[i];
            chmax(ans, tmp);
        }
        if(B[i] == 'W'){
            int tmp = A[i];
            chmax(ans, tmp);
        }
    }

    cout << ans << endl;
    return 0;
}
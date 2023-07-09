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

int main(){
    // 入力
    int N, Q, state  = 1; // state: 反転しているかどうか
    int E[200009]; // 反転操作を無視した際の配列の状態
    cin >> N >> Q;
    for(int i = 1; i <= N; i++) E[i] = i;

    // クエリの処理
    for(int i = 1; i <= Q; i++){
        int Type, x, y;
        cin >> Type;

        // 変更操作
        if(Type == 1){
            cin >> x >> y;
            if(state == 1) E[x] = y;
            if(state == 2) E[N+1-x] = y;
        }

        // 反転操作
        if(Type == 2){
            if(state == 1) state = 2;
            else if(state == 2) state = 1;
        }

        // 取得操作
        if(Type == 3){
            cin >> x;
            if(state == 1) cout << E[x] << endl;
            if(state == 2) cout << E[N+1-x] << endl;
        }
    }
    return 0;
}
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

int N, Q, T[509]; // T[i]: i行目にはもともと何行目の値が書かれているか
int A[509][509], Type[200009];

int main(){
    // 入力
    cin >> N;
    for(int i = 1; i <= N; i++){
        for(int j = 1; j <= N; j++){
            cin >> A[i][j];
        }
    }
    cin >> Q;
    for(int i = 1; i <= N; i++) T[i] = i; // 初期化

    // 処理
    int ans[200009];
    int cnt = 1;
    for(int i = 1; i <= Q; i++){
        int Type, x, y;
        cin >> Type;

        // 交換操作
        if(Type == 1){
            cin >> x >> y;
            swap(T[x], T[y]);
        }

        // 取得操作
        if(Type == 2){
            cin >> x >> y;
            ans[cnt] = A[T[x]][y];
            cnt++;
        }
    }

    // 出力
    for(int i = 1; i <= cnt-1; i++) cout << ans[i] << endl;
    return 0;
}
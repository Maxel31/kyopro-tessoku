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
    int N, M;
    cin >> N >> M;
    int A[200009];
    for(int i = 1; i <= M; i++) cin >> A[i];

    // 不正解を数える問題に言い換える
    int WA[200009]; // 各生徒の不正解数を記録する
    for(int i = 1; i <= N; i++) WA[i] = 0; // 初期化
    for(int i = 1; i <= M; i++){
        WA[A[i]]++;
    }

    // 出力
    for(int i = 1; i <= N; i++){
        cout << M - WA[i] << endl;
    }
    return 0;
}
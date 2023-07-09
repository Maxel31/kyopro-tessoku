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
    int N, X;
    string A;
    cin >> N >> X >> A;
    queue<int> que;

    // 初期化
    que.push(X-1);
    A[que.front()] = '@';

    // 処理
    while(!que.empty()){
        int tmp = que.front();
        que.pop();
        if(A[tmp-1] == '.'){
            que.push(tmp-1);
            A[tmp-1] = '@';
        }
        if(A[tmp+1] == '.'){
            que.push(tmp+1);
            A[tmp+1] = '@';
        }
    }

    // 出力
    cout << A << endl;
    return 0;
}
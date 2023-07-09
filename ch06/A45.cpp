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

// 不変量に注目する
// 本問では,それぞれの色のスコアを，白: 0, 青: 1, 赤: 2として,
// スコアの合計を3で割った余りが不変量

int main(){
    // 入力 , 処理
    int N;
    cin >> N;
    char C;
    cin >> C;
    char A[200009];
    int score = 0;

    for(int i = 1; i <= N; i++) cin >> A[i]; 
    for(int i = 1; i <= N; i++){
        if(A[i] == 'W') score+=0;
        if(A[i] == 'B') score+=1;
        if(A[i] == 'R') score+=2;
    }

    // 判定
    if((score % 3 == 0) && C == 'W') cout << "Yes" << endl;
    else if((score % 3 == 1) && C == 'B') cout << "Yes" << endl;
    else if((score % 3 == 2) && C == 'R') cout << "Yes" << endl;
    else{
        cout << "No" << endl;
        return 0;
    }
    return 0;
}
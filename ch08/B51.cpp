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
    string S;
    cin >> S;
    stack<int> st;

	// 左から順番に見ていく
	// 文字列は 0 文字目から始まることに注意
	for (int i = 0; i < S.size(); i++) {
		if (S[i] == '(') {
			st.push(i + 1);
		}
		if (S[i] == ')') {
			cout << st.top() << " " << i + 1 << endl;
			st.pop();
		}
	}
	return 0;
}
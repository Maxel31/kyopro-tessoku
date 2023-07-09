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
    int Q;
    cin >> Q;
    stack<string> st;

    vector<string> ans;
    for(int i = 1; i <= Q; i++){
        int query;
        cin >> query;
        if(query == 1){
            string x;
            cin >> x;
            st.push(x);
        }
        if(query == 2){
            if(!st.empty()){
                ans.push_back(st.top());
            }
        }
        if(query == 3){
            if(!st.empty()){
                st.pop();
            }
        }
    }

    // 出力
    for(int i = 0; i < ans.size(); i++){
        cout << ans[i] << endl;
    }
    return 0;
}
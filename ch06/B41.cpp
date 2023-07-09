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

int main(){
    int X, Y;
    cin >> X >> Y;

    // 「最後の処理」から考える
    vector<P> ans;
    while(X >= 2 || Y >= 2){
        ans .push_back(make_pair(X, Y));
        if(X > Y) X -= Y;
        else Y -= X;
    }
    reverse(ans.begin(), ans.end());

    // 出力
    if(ans.empty()){
        cout << 0 << endl;
        return 0;
    }
    cout << ans.size() << endl;
    for(auto p : ans){
        cout << p.first << " " << p.second << endl;
    }
    return 0;
}
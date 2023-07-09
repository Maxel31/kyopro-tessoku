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

// 選び方のパターンは4つ
// (表，裏) = (正，正), (正，負), (負，正), (負，負)

ll N;
ll A[100009], B[100009];
ll solve(int omote, int ura){
    ll sum = 0;
    for(int i = 1; i <= N; i++){
        ll card1 = A[i]; if(omote == 2) card1 = -A[i];
        ll card2 = B[i]; if(ura == 2) card2 = -B[i];
        // カードiは選ぶべきか
        if(card1 + card2 >= 0) sum += card1 + card2;
    }
    return sum;
}

int main(){
    // 入力
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> A[i] >> B[i];
    }

    ll ans1 = solve(1, 1);
    ll ans2 = solve(1, 2);
    ll ans3 = solve(2, 1);
    ll ans4 = solve(2, 2);

    cout << max({ans1, ans2, ans3, ans4}) << endl;  
    return 0;
}
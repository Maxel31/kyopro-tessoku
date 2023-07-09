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

// 最後に3つ色が連続しているところがあるかどうか

int main(){
    int N;
    cin >> N;
    char S[200009];
    for(int i = 1; i <= N; i++) cin >> S[i];

    bool flag = false;
    for(int i = 1; i <= N-2; i++){
        if(S[i] == S[i+1] && S[i+1] == S[i+2]){
            flag = true;
            break;
        }
    }

    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}
#include <bits/stdc++.h>    
using namespace std;
using ll = long long;

int main(){
    // 入力
    int N, K;
    cin >> N >> K;

    if(2 * N - 2 > K) cout << "No" << endl;
    else if(K % 2 == 1) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}
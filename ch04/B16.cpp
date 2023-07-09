#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int N;
int h[100009], cost[100009];

int main(){
    // 入力
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> h[i];

    // 動的計画法
    cost[1] = 0;
    cost[2] = abs(h[2] - h[1]);
    for(int i = 3; i <= N; i++){
        cost[i] = min(cost[i - 1] + abs(h[i] - h[i - 1]), cost[i - 2] + abs(h[i] - h[i - 2]));
    }
    cout << cost[N] << endl;
    return 0;
}
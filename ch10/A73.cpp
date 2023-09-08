#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL<<60;

int N, M;
int A[100009], B[100009], C[100009], D[100009];
bool tree[100009];

int main(){
    // 入力
    cin >> N >> M;
    for(int i = 1; i <= M; i++){
        cin >> A[i] >> B[i] >> C[i] >> D[i];
        if(D[i] == 1) tree[i] = true;
        else tree[i] = false;
    }
}
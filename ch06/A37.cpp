#include <bits/stdc++.h>    
using namespace std;
using ll = long long;

int main(){
    int N, M, B;
    int A[200009], C[200009];
    cin >> N >> M >> B;
    for(int i = 1; i <= N; i++) cin >> A[i];
    for(int i = 1; i <= M; i++) cin >> C[i];

    ll total = 0;
    for(int i = 1; i <= N; i++) total += A[i] * M;
    total += B * N * M;
    for(int i = 1; i <= M; i++) total += C[i] * N;

    cout << total << endl;
    return 0;
}
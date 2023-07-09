#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll operation(ll A, char t, ll a){
    if(t == '+'){
        A += a;
        A %= 10000;
        if(A < 0) A += 10000;
    }
    if(t == '*'){
        A *= a;
        A %= 10000;
        if(A < 0) A += 10000;
    }
    if(t == '-'){
        A -= a;
        A %= 10000;
        if(A < 0) A += 10000;
    }
    return A;
}

int main(){
    int N, A[100009];
    char T[100009];
    cin >> N;
    for(int i = 1; i <= N; i++){
        cin >> T[i] >> A[i];
    }

    ll ans[100009];
    ans[1] = operation(0, T[1], A[1]);
    for(int i = 2; i <= N; i++){
        ans[i] = operation(ans[i-1], T[i], A[i]);
    }

    for(int i = 1; i <= N; i++){
        cout << ans[i] << endl;
    }
    return 0;
}
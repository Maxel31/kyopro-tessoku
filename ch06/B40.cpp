#include <bits/stdc++.h>    
using namespace std;
using ll = long long;

int main(){
    int N, A[200009];
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> A[i];

    ll ans = 0;
    for(int i = 1; i <= N-1; i++){
        for(int j = i+1; j <= N; j++){
            if(((A[i] + A[j]) % 100) == 0) ans++;
        }
    }
    cout << ans << endl;
    return 0;
}
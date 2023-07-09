#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int N;
    cin >> N;

    for(int i = 2; i <= N; i++){
        bool flag = false;
        for(int j = 2; j*j <= i; j++){
            if(i % j == 0){
                flag = true;
                break;
            }
        }
        if(!flag) cout << i << endl;
    }
    return 0;
}
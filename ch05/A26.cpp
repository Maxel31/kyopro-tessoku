#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int Q;
    int X[100009];

    // 入力
    cin >> Q;
    for(int i = 1; i <= Q; i++) cin >> X[i];

    // 2~√Qまでの約数を持つか調べる
    for(int i = 1; i <= Q; i++){
        bool flag = false;
        for(int j = 2; j * j <= X[i]; j++){
            if(X[i] % j == 0){
                flag = true;
                break;
            }
        }
        if(flag) cout << "No" << endl;
        else cout << "Yes" << endl;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL<<60;

int main(){
    // 入力
    int Q;
    cin >> Q;
    int Query[100009];

    map<string, int> mp;
    for(int i = 1; i <= Q; i++){
        cin >> Query[i];
        if(Query[i] == 1){
            string s;
            cin >> s;
            int x;
            cin >> x;
            mp[s] = x;
        }
        if(Query[i] == 2){
            string s;
            cin >> s;
            if(mp.count(s)){
                cout << mp[s] << endl;
            }else{
                cout << 0 << endl;
            }
        }
    }

    return 0;
}
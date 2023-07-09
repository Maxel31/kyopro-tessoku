#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL<<60;

int main(){
    int Q;
    cin >> Q;
    set<int> st;

    // 処理
    for(int i = 1; i <= Q; i++){
        int type;
        cin >> type;
        if(type == 1){
            int x;
            cin >> x;
            st.insert(x);
        }
        if(type == 2){
            int x;
            cin >> x;
            st.erase(x);
        }
        if(type == 3){
            int x;
            cin >> x;
            auto itr = st.lower_bound(x);
            if(itr == st.end()) cout << -1 << endl;
            else cout << *itr << endl;
        }
    }

    return 0;
}
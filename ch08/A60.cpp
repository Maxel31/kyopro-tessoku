#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL<<60;

int N, A[200009];
int ans[200009];
stack<pair<int,int>> level2;

int main(){
    // 入力
    cin >> N;
    for(int i = 1; i <= N; i++) cin >> A[i];

    // 処理
    for(int i = 1; i <= N; i++){
        if(i >= 2){
            level2.push(make_pair(i-1, A[i-1]));
            // 今の株価より高い株価に行き当たるまで遡る
            while(!level2.empty()){
                int kabuka = level2.top().second;
                if(kabuka <= A[i]) level2.pop(); // 今の株価よりも前の株価が低いならpop
                else break;
            }
        }

        // 起算日の決定
        if(level2.empty()) ans[i] = -1;
        else ans[i] = level2.top().first;
    }

    // 出力
    for(int i = 1; i <= N; i++) cout << ans[i] << " ";
    cout << endl;
    return 0;
}
#include <bits/stdc++.h>    
using namespace std;
using ll = long long;

int N, L[300009], R[300009];
vector<pair<int, int>> tmp; // 映画を終了時間の速い順にソートするための一時変数

int main(){
    // 入力
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> L[i] >> R[i];
        tmp.push_back({R[i], L[i]});
    }

    // Rの小さい順にソート
    sort(tmp.begin(), tmp.end());
    for(int i = 1; i <= N; i++){
        R[i] = tmp[i - 1].first;
        L[i] = tmp[i - 1].second;
    }

    // 終了時間の早いものから順に映画を見ていく
    int CurrentTime = 0, ans = 0;
    for(int i = 1; i <= N; i++){
        if(CurrentTime <= L[i]){
            ans++;
            CurrentTime = R[i];
        }
    }
    cout << ans << endl;
    return 0;
}
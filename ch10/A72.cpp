#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL<<60;

int H, W, K;
int ans = 0;
char c[19][109], d[19][109];

// 残りx回の操作で，最大何個のマスを黒くできるか
int CanPaintRow(int x){
    // 各列に対する「白マスの個数」を数える ⇒ 多い順にソート
    vector<P> column;
    for(int j = 1; j <= W; j++){
        int cnt = 0;
        for(int i = 1; i <= H; i++){
            if(c[i][j] == '.') cnt++;
        }
        column.push_back(P(cnt, j));
    }
    sort(column.begin(), column.end());
    reverse(column.begin(), column.end());

    // 列に対する操作(黒く塗る)
    for(int j = 0; j < x; j++){
        int idx = column[j].second;
        for(int i = 1; i <= H; i++){
            d[i][idx] = '#';
        }
    }

    // カウント
    int ret = 0;
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            if(d[i][j] == '#') ret++;
        }
    }
    return ret;
}

int main(){
    // 入力
    cin >> H >> W >> K;
    for(int i = 1; i <= H; i++){
        for(int j = 1; j <= W; j++){
            cin >> c[i][j];
        }
    }

    // bit 全探索
    for(int t = 0; t < (1 << H); t++){
        // 初期化
        for(int i = 1; i <= H; i++){
            for(int j = 1; j <= W; j++){
                d[i][j] = c[i][j];
            }
        }
    

        // 行に対する操作
        int x = K;
        for(int i = 1; i <= H; i++){
            int div = (1 << (i - 1));
            if((t / div) % 2 == 0) continue;
            x--;
            for(int j = 1; j <= W; j++){
                d[i][j] = '#';
            }
        }

        if(x >= 0){
            int subans = CanPaintRow(x);
            ans = max(ans, subans);
        }
    }
    // 出力
    cout << ans << endl;
    return 0;
}
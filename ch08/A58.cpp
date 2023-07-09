#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL<<60;

class SegmentTree{
public:
        int dat[300000], siz = 1;

        // dat初期化
        void init(int N){
            siz = 1;
            while(siz < N) siz *= 2;
            for(int i = 1; i < siz*2; i++) dat[i] = 0;
        }

        // クエリ1に対する処理 posの値をxに更新
        void update(int pos, int x){
            pos = pos + siz - 1;
            dat[pos] = x;
            // 最大値の更新
            while(pos >= 2){
                pos /= 2;
                dat[pos] = max(dat[pos*2], dat[pos*2+1]); // 左下，右下どっちが大きいか
            }
        }

        // クエリ2に対する処理, 探索セル範囲[a, b) を移動させながら]
        // 半開区間 [l,r) の最大値を求める
        int Ans_Max_Score(int l, int r, int a, int b, int u){
            // 対象区間に一切含まれない場合
            if(r <= a || b <= l) return -(1 << 30);
            // 対象区間が完全に含まれる場合
            if(l <= a && b <= r) return dat[u];

            int m = (a + b) / 2;
            // 再帰関数
            int valL=Ans_Max_Score(l,r,a,m,u*2);
            int valR=Ans_Max_Score(l,r,m,b,u*2+1);
            return max(valL, valR);
        }
};


// 処理
int N, Q;
int Query[100009], pos[100009], x[100009], l[100009], r[100009];
SegmentTree RMQ;

int main(){
    // 入力
    cin >> N >> Q;
    for(int i = 1; i <= Q; i++){
        cin >> Query[i];
        if(Query[i] == 1) cin >> pos[i] >> x[i];
        if(Query[i] == 2) cin >> l[i] >> r[i];
    }

    RMQ.init(N);
    // 処理
    for(int i = 1; i <= Q; i++){
        if(Query[i] == 1){
            RMQ.update(pos[i], x[i]);
        }
        if(Query[i] == 2){
            cout << RMQ.Ans_Max_Score(l[i], r[i], 1, RMQ.siz+1, 1) << endl;
        }
    }
    return 0;
}
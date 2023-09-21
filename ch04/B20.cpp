#include <bits/stdc++.h>
using namespace std;
# define rep(i, n) for(int i =1; i <= (n); ++i)
using ll = long long;
using P = pair<int, int>;
const long long INF = 1LL << 60;

// 編集距離問題

string S, T;
int dp[2009][2009];

int main(){
	// 入力
	cin >> S >> T;
	int N = S.size(), M = T.size();

	// 動的計画法
	dp[0][0] = 0;
	for(int i = 0; i <= N; i++){
		for(int j = 0; j <= M; j++){
			if(i >= 1 && j >= 1 && S[i-1] == T[j-1]){
				dp[i][j] = min({dp[i-1][j-1], dp[i-1][j] + 1, dp[i][j-1] + 1});
			}
			else if(i >= 1 && j >= 1){
				dp[i][j] = min({dp[i-1][j]+1, dp[i][j-1]+1, dp[i-1][j-1]+1});
			}
			else if(i >= 1){
				dp[i][j] = dp[i-1][j] + 1;
			}
			else if(j >= 1){
				dp[i][j] = dp[i][j-1] + 1;
			}
		}
	}

	// 出力
	cout << dp[N][M] << endl;
	return 0;
}
#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <map>
#include <set>
using namespace std;

const int mod = 1e9+7;

void add_self(int& a, int b){
	a += b;
	if(a >= mod)
		a -= mod;
	return;
}

int main(void){
	int n;
	cin >> n;
	vector<vector<int> > can(n, vector<int>(n));
	for(int i = 0;i < n;i++)
		for(int j = 0;j < n;j++)
			cin >> can[i][j];
	vector<int> dp(1 << n);
	dp[0] = 1;
	for(int mask = 0;mask < (1 << n)-1;mask++){ // 1- means women matched
			int m = __builtin_popcount(mask);
			for(int w = 0;w < n;w++){
					if(can[m][w] == 1 && !(mask & (1 << w))){
							int new_mask = mask^(1 << w);
							add_self(dp[new_mask], dp[mask]);
					}
			}
	}
	cout << dp[(1<<n)-1] << endl;
}

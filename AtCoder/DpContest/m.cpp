#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define mod 1e9+7
#define pb push_back

void add_self(int& here, int y){
	here += y;
	if(here >= mod)
		here -= mod;
	return;
}

void sub_self(int& here, int y){
	here -= y;
	if(here < 0)
		here += mod;
	return;
}

int main(void){
	int n, k;
	cin >> n >> k;
	vector<int> a(n);
	for(int i = 0;i < n;i++)
		cin >> a[i];
	vector<int> dp(k+1, 0); // dp[i] - used candies
	dp[0] = 1;
	for(int i = 0;i < n;i++){ // n children
		vector<int> fake(k+1);
		for(int used = k;used >= 0;used--){
			int l = used+1;
			int r = used+min(k-used, a[i]);
			if(l <= r){
				add_self(fake[l], dp[used]);
				if(r < k){
					sub_self(fake[r+1], dp[used]);
				}
			}
		}
		int temp = 0;
		for(int x = 0;x <= k;x++){
			add_self(temp, fake[x]);
			add_self(dp[x], temp);
		}
	}
	cout << dp[k] << endl;
}

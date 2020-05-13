#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

struct compare{
	bool operator()(const int& a, const int& b) const {
		return b < a;
	}
};

int main(void){
	int n;
	cin >> n;
	map<int, long long> dp;
	vector<int> height(n);
	vector<int> value(n);
	for(int i = 0;i < n;i++){
		cin >> height[i];
	}
	for(int i = 0;i < n;i++){
		cin >> value[i];
	}
	for(int i = 0;i < n;i++){
		dp[height[i]] = (long long)value[i];
		auto it = dp.find(height[i]);
		it++;
		if(it == dp.end())
			continue;
		cout << height[i] << ' ' << it->first << endl;
		dp[height[i]] += (long long)it->second;
	}
	auto it = dp.begin();
	long long ans = 0;
	for(;it != dp.end();it++)
			ans = max(ans, it->second);
	cout << ans << endl;
	return 0;
}

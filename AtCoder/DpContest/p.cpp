#include <iostream>
#include <algorithm>
#include <vector>
#include <bitset>
#include <map>
#include <set>
#include <queue>
using namespace std;

#define pii pair<int, int>
#define mp make_pair
#define pb push_back

int n;
const int mod = 1e9+7;
map<int, vector<int> > to_edge;
vector<vector<long long> > dp;

int func(int x, bool white);

bool compare(pii x, pii y){
	if(x.first < y.first)
		return true;
	else if(x.first == y.first)
		return x.second < y.second;
	return false;
}

int main(void){
	cin >> n;
	// initialize dp
	for(int i = 0;i < n;i++){
		vector<long long> temp(2, -1);
		dp.pb(temp);
	}
	vector<vector<int> > edges(n);
	for(int i = 0;i < n-1;i++){
		int x, y;
		cin >> x >> y;
		edges[x-1].pb(y-1);
		edges[y-1].pb(x-1);
	}
	queue<int> q;
	q.push(0);
	vector<bool> visited(n);
	while(!q.empty()){
		int x = q.front();
		q.pop();
		visited[x] = true;
		int size = edges[x].size();
		bool none = true;
		for(int i = 0;i < size;i++){
			if(visited[edges[x][i]] == false){
				none = false;
				to_edge[x].pb(edges[x][i]);
				q.push(edges[x][i]);
			}
		}
		if(none){
			vector<int> emp_vec;
			to_edge[x] = emp_vec;
		}
	}
	dp[0][0] = func(0, true);
	dp[0][1] = func(0, false);
//	for(auto it = to_edge.begin();it != to_edge.end();it++){
//		cout << it->fisrt << " -> ";
//		int 
	cout << (dp[0][0] + dp[0][1])%mod << endl;
	return 0;
}

int func(int x, bool white){
	if(white){
		if(dp[x][0] != -1)
			return dp[x][0];
	}
	else
		if(dp[x][1] != -1)
			return dp[x][1];
	auto it = to_edge.find(x);
	int edge_size = to_edge[x].size();
	if(edge_size == 0){
		if(white)
			dp[x][0] = 1;
		else
			dp[x][1] = 1;
		return 1;
	}
	long long ans = 0;
	long long tempans = 1;
	for(int i = 0;i < edge_size;i++){
		int temp = 0;
		temp += func(it->second[i], true);
		if(white)
			temp += func(it->second[i], false);
		tempans *= temp;
	}
	ans %= tempans;
	if(white){
		dp[x][0] = ans;
		return ans;
	}
	else{
		dp[x][1] = ans;
		return ans;
	}
}

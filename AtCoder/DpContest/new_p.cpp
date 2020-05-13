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
#define imie(...) " [" << #__VA_ARGS__ ": " << (__VA_ARGS__) << "] "

vector<vector<int> > to_edge;
const int mod = 1e9+7;
vector<vector<int> > dp;

void add_self(int& x, int y){
	x += y;
	if(x >= mod)
		x -= mod;
	return;
}
long long mul_self(long long x, long long y){
	if(y == 1)
		return x;
	long long temp = mul_self(x, y/2);
	if(temp >= mod)
		temp %= mod;
	temp = temp+temp;
	if(temp >= mod)
		temp %= mod;
	if(y%2 == 1)
		temp += x;
	if(temp >= mod)
		temp %= mod;
	return temp;
}

int func(int root, bool white);

int main(void){
	int n;
	cin >> n;
	to_edge.resize(n);
	for(int i = 0;i < n;i++){
		vector<int> temp(2, -1);
		dp.pb(temp);
	}
	vector<vector<int> > edges(n);
	for(int i = 0;i < n-1;i++){
		int x, y;
		cin >> x >> y;
		edges[x-1].pb(y-1);
		edges[y-1].pb(x-1);
	}
	int root = 0;
	queue<int> q;
	q.push(0);
	vector<bool> visited(n);
	while(!q.empty()){
		int temp = q.front();
		q.pop();
		visited[temp] = true;
		int size = edges[temp].size();
		for(int i = 0;i < size;i++){
			if(visited[edges[temp][i]] == true)
				continue;
			to_edge[temp].pb(edges[temp][i]);
			q.push(edges[temp][i]);
		}
	}
	int black = func(0, false);
	int white = func(0, true);
	add_self(white, black);
	cout << white << endl;
	return 0;
}

int func(int root, bool white){
	if(white){
		if(dp[root][0] != -1)
			return dp[root][0];
	}
	else
		if(dp[root][1] != -1)
			return dp[root][1];
	int child_size = to_edge[root].size();
	if(child_size == 0){
		if(white)
			dp[root][0] = 1;
		else
			dp[root][1] = 1;
		return 1;
	}
	long long ans = 1;
	for(int i = 0;i < child_size;i++){
		int child = to_edge[root][i];
		int temp = 0;
		if(white)
			temp = func(child, true) + func(child, false);
		else
			temp = func(child, true);
		add_self(temp, 0);
		ans = mul_self(ans, (long long)temp);
	}
	cout << imie(ans) << endl;
	if(white)
		dp[root][0] = (int) ans;
	else
		dp[root][1] = (int) ans;
	return (int) ans;
}

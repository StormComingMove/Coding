#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <unordered_map>
#include <set>
#include <climits>
using namespace std;

#define pb push_back
#define mp make_pair
#define pii pair<int, int>
#define ll long long

const int mod = 1e9+7;

void add_self(int& x, int y){
	x += y;
	if(x >= mod)
		x -= mod;
	return;
}

int gcd(int x, int y){
	if(x < y)
		return gcd(y, x);
	if(x%y == 0)
		return y;
	return gcd(y, x%y);
}

int gcdl(ll x, int y){
	if(x < (ll)y)
		return gcdl((ll)y, (int)x);
	if(x%(ll)y == 0)
		return y;
	return gcd((ll)y, x%(ll)y);
}

int main(void){
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0;i < n;i++)
		cin >> v[i];
	if(n == 2){
		long long ans = (ll)v[0] * (ll)v[1];
		ans = ans / (ll)gcd(v[0], v[1]);
		cout << ans << endl;
		return 0;
	}
	vector<int> prefix(n);
	prefix[0] = v[0];
	for(int i = 1;i < n;i++){
		prefix[i] = gcd(v[i], prefix[i-1]);
	}
	vector<int> suffix(n);
	suffix[n-1] = v[n-1];
	for(int i = n-2;i >= 0;i--){
		suffix[i] = gcd(v[i], suffix[i+1]);
	}
	vector<int> v_new(n);
	v_new[0] = suffix[1];
	v_new[n-1] = prefix[n-2];
	for(int i = 1;i < n-1;i++){
		v_new[i] = gcd(prefix[i-1], suffix[i+1]);
	}
	ll ans = v_new[0];
	for(int i = 1;i < n;i++){
		int temp = gcdl(ans, v_new[i]);
		ans = (ans * (ll)v_new[i])/(ll)temp;
	}

	cout << ans << endl;
	return 0;
}

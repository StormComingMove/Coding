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


int main(void){

	vector<int> first_div(1000001,-1);

	vector<int> primes;
	primes.pb(2);
	first_div[2] = 2;
	for(int i = 3;i <= 1000;i++){
		int size = primes.size();
		bool check = false;
		for(int j = 0;j < size;j++){
			if(i%primes[j] == 0){
				check = true;
				first_div[i] = primes[j];
				break;
			}
		}
		if(check == false){
			primes.pb(i);
			first_div[i] = i;
		}
	}
	int t;
	cin >> t;
	int size = primes.size();
	while(t--){
		int n, k;
		cin >> n >> k;
		if(first_div[n] == -1){
			bool check = false;
			for(int i = 0;i < size;i++){
				if(n%primes[i] == 0){
					check = true;
					first_div[n] = primes[i];
					break;
				}
			}
			if(check == false)
				first_div[n] = n;
		}
		long long ans = n + first_div[n];
		--k;
		ans += 2*k;
		cout << ans << endl;
	}
	return 0;
}

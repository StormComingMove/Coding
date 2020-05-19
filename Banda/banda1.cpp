#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main(void){
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0;i < n;i++)
		cin >> v[i];
	stack<pair<int, int> > nextMax;
	stack<pair<int, int> > beforeMax;
	vector<int> right(n);
	for(int i = 0;i < n;i++)
		right[i] = n-i-1;
	vector<int> left(n);
	for(int i = 0;i < n;i++)
		left[i] = i;
	for(int i = 0;i < n;i++){
		if(nextMax.empty()){
			nextMax.push(make_pair(v[i], i));
			continue;
		}
		int top_val = nextMax.top().first;
		int top_idx = nextMax.top().second;
		if(top_val >= v[i]){
			nextMax.push(make_pair(v[i], i));
			continue;
		}
		while(top_val < v[i]){
			nextMax.pop();
			right[top_idx] = i-top_idx-1;
			if(nextMax.empty())
				break;
			top_val = nextMax.top().first;
			top_idx = nextMax.top().second;
		}
		nextMax.push(make_pair(v[i], i));
	}
	for(int i = n-1;i >= 0;i--){
		if(beforeMax.empty()){
			beforeMax.push(make_pair(v[i], i));
			continue;
		}
		int top_val = beforeMax.top().first;
		int top_idx = beforeMax.top().second;
		if(top_val > v[i]){
			beforeMax.push(make_pair(v[i], i));
			continue;
		}
		while(top_val <= v[i]){
			beforeMax.pop();
			left[top_idx] = top_idx-i-1;
			if(beforeMax.empty())
				break;
			top_val = beforeMax.top().first;
			top_idx = beforeMax.top().second;
		}
		beforeMax.push(make_pair(v[i], i));
	}
	int ans = 0;
	for(int i = 0;i < n;i++){
		cout << "left -> " << left[i] << ", right -> " << right[i] << ", value - " << v[i] << endl;
		ans += (left[i]+1)*(right[i]+1)*v[i];
	}
	cout << ans << endl;
	return 0;
}

#include <iostream>
#include <vector>
#include <map>
#include <queue>
#include <unordered_map>
using namespace std;

struct compare {
	bool operator() (pair<int, int> x, pair<int, int> y){ // min heap
	if(x.first < y.first)
			return false;
		return true;
	}
};

class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		const int n = nums.size();
		unordered_map<int, int> hash;
		for(int i = 0;i < n;i++)
			hash[nums[i]]++;
		priority_queue<pair<int, int>, vector<pair<int, int> >, compare> pq;
		for(auto it = hash.begin();it != hash.end();it++){
			int size = pq.size();
			int value = it->first;
			int score = it->second;
			if(size == k){
				if(pq.top().first < score){
					pq.pop();
					pq.push(make_pair(score, value));
				}
			}
			else{
				pq.push(make_pair(score, value));
			}
		}
		vector<int> ans;
		while(!pq.empty()){
			ans.push_back(pq.top().second);
			pq.pop();
		}
		return ans;
    }
};

int main(void){
	Solution* s = new Solution();
	int n;
	int k;
	cin >> n >> k;
	vector<int> v(n);
	for(int i = 0;i < n;i++)
		cin >> v[i];
	vector<int> ans = s->topKFrequent(v, k);
	int size = ans.size();
	for(int i = 0;i < size;i++)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}

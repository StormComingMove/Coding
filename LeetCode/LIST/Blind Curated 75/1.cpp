#include <iostream>
#include <map>
#include <vector>
#include <climits>
#include <stack>
#include <queue>
#include <set>
#include <unordered_map>
using namespace std;

// add Solution class below

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map <int, int> hash;
		int size = nums.size();
		vector<int> ret;
		for(int i = 0;i < size;i++){
			int find_elem = target - nums[i];
			auto it = hash.find(find_elem);
			if(it != hash.end()){
				ret.push_back(it->second);
				ret.push_back(i);
				return ret;
			}
			hash[nums[i]] = i;
		}
		return ret;
    }
};

int main(void){
	Solution* s = new Solution();
	// add code below
	int n, target;
	cin >> n >> target;
	vector<int> input(n);
	for(int i = 0;i < n;i++)
		cin >> input[i];
	vector<int> ans = s->twoSum(input, target);
	int size = ans.size();
	for(int i = 0;i < size;i++)
		cout << ans[i] << ' ';
	cout << endl;
	return 0;
}

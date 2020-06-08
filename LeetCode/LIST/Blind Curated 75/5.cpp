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
    vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		const int n = nums.size();
		vector<vector<int>> ans;
		for(int i = 0;i < n-2;i++){
			if(ans.size() > 0){
				if(ans[ans.size()-1][0] == nums[i])
					continue;
			}
			int target = -nums[i];
			int j = i+1;
			int k = n-1;
			bool found = false;
			int prevj = 0;
			while(j < k){
				if(nums[j] + nums[k] == target){
					if(!found){
						found = true;
						prevj = nums[j];
						ans.push_back({nums[i], nums[j], nums[k]});
					}
					else if(prevj != nums[j]){
						prevj = nums[j];
						ans.push_back({nums[i], nums[j], nums[k]});
					}
					j++;
					k--;
				}
				else if(nums[j] + nums[k] < target){
					j++;
				}
				else
					k--;
			}
		}
		return ans;
    }
};

int main(void){
	Solution* sol = new Solution();
	// add code below
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0;i < n;i++)
		cin >> v[i];
	vector<vector<int> > ans = sol->threeSum(v);
	int size = ans.size();
	for(int i = 0;i < size;i++)
		cout << ans[i][0] << ' ' << ans[i][1] << ' ' << ans[i][2] << endl;
	return 0;
}

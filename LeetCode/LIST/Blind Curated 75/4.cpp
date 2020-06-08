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
    int maxArea(vector<int>& height) {
		const int n = height.size();
		int ans = 0;
		int first = 0, second = n-1;
		while(first < second){
			ans = max(ans, (second-first)*min(height[first], height[second]));
			if(height[first] > height[second])
				second--;
			else if(height[first] < height[second])
				first++;
			else{
				first++;
				second--;
			}
		}
		return ans;
    }
};

int main(void){
	Solution* s = new Solution();
	// add code below
	int n;
	cin >> n;
	vector<int> v(n);
	for(int i = 0;i < n;i++)
		cin >> v[i];
	cout << s->maxArea(v) << endl;
	return 0;
}

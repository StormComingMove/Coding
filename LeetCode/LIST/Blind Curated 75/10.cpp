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
    int search(vector<int>& nums, int target) {
		const int n = nums.size();
		int left = 0;
		int right = n-1;
		while(left <= right){
			int mid = left + (right-left)/2;
			if(nums[mid] == target)
				return mid;
			bool we_big = false;
			if(nums[mid] < nums[right])
				we_big = true;
			bool target_big = false;
			if(target < nums[right])
				target_big = true;
			if(nums[mid] < target){
				
    }
};

int main(void){
	Solution* sol = new Solution();
	// add code below
	
	return 0;
}

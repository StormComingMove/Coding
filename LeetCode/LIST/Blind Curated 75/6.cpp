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

 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
		ListNode* temp = head;
		int len = 0;
		while(temp != nullptr){
			len++;
			temp = temp->next;
		}
		int remove_pos = len - n;
		temp = head;
		if(remove_pos == 0){
			head = head->next;
			return head;
		}
		while(remove_pos > 1){
			temp = temp->next;
			remove_pos--;
		}
		temp->next = temp->next->next;
		return head;
    }
};

int main(void){
	Solution* sol = new Solution();
	// add code below
	
	return 0;
}

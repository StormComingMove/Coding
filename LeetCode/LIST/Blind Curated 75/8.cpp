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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
		if(l1 == nullptr)
			return l2;
		if(l2 == nullptr)
			return l1;
		ListNode* temp1 = l1;
		ListNode* temp2 = l2;
		ListNode* head = nullptr;
		ListNode* temp;
		while(temp1 != nullptr || temp2 != nullptr){
			if(temp1 != nullptr && temp2 != nullptr){
				if(head == nullptr){
					if(temp1->val < temp2->val){
						head = temp1;
						temp = head;
						temp1 = temp1->next;
					}
					else{
						head = temp2;
						temp = head;
						temp2 = temp2->next;
					}
					continue;
				}
				if(temp1->val < temp2->val){
					temp->next = temp1;
					temp = temp1;
					temp1 = temp1->next;
				}
				else{
					temp->next = temp2;
					temp = temp2;
					temp2 = temp2->next;
				}
			}
			else if(temp1 == nullptr){
				temp->next = temp2;
				temp = temp2;
				temp2 = temp2->next;
			}
			else{
				temp->next = temp1;
				temp = temp1;
				temp1 = temp1->next;
			}
		}
		return head;
    }
};

int main(void){
	Solution* sol = new Solution();
	// add code below

	return 0;
}

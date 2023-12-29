/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        ListNode* ans = new ListNode(-5001);
        while(head != nullptr){
            ListNode* iter = ans;
            ListNode* prev = ans;
            bool flag = true;
            while(iter != nullptr){
                if(iter->val < head->val){
                    prev = iter;
                    iter = iter->next;
                }
                else{
                    prev->next = head;
                    head = head->next;
                    prev->next->next = iter;
                    flag = false;
                    break;
                }
            }
            if(flag){
                prev->next = head;
                head = head->next;
                prev->next->next = nullptr;
            }
        }
        return ans->next;
    }
};
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
    ListNode* sortList(ListNode* head) {
        if(head == nullptr || head->next == nullptr){
            return head;
        }
        
        ListNode* left = head;
        ListNode* mid;
        ListNode* right = head;
        while(right != nullptr && right->next != nullptr){
            mid = left;
            left = left->next;
            right = right->next->next;
        }
        mid->next = nullptr;
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(left);
        return merge(l1, l2);
        
    }
    ListNode* merge(ListNode* l1, ListNode* l2){
        if(l1 == nullptr)
            return l2;
        if(l2 == nullptr)
            return l1;
        
        ListNode *ans = new ListNode;
        ListNode* iter = ans;
        
        while(l1 != nullptr && l2 != nullptr){
            if(l1->val > l2->val){
                iter->next = l2;
                l2 = l2->next;
                iter = iter->next;
            }
            else{
                iter->next = l1;
                l1 = l1->next;
                iter = iter->next;
            }
        }
        if(l1 != nullptr)
            iter->next = l1;
        if(l2 != nullptr)
            iter->next = l2;
        return ans->next;
    }
};
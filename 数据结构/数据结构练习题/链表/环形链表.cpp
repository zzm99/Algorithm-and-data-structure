/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(!head || !head->next) return false;
        ListNode* first = head;
        ListNode* second = head;
        while(first && second){
            if(first->next) first = first->next->next;
            else return false;
            second = second->next;
            if(!second) return false;
            if(first == second) return true;
        }
        return false;
    }
};
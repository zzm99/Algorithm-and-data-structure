// https://leetcode-cn.com/problems/remove-linked-list-elements/
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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* t = new ListNode(0);
        t->next = head;
        ListNode* p = t;
        while(p && p->next){
            ListNode* next = p->next;
            if(next->val == val){
                p->next = next->next;
                delete next;
            }else{
                p = p->next;
            }
        }
        return t->next;
    }
};
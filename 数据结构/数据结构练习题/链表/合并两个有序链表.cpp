// https://leetcode-cn.com/problems/merge-two-sorted-lists/
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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* ret = new ListNode(-1);
        ListNode* hh = ret;
        while(l1&&l2){
            int c1 = l1->val;
            int c2 = l2->val;
            if(c1 < c2){
                ret->next = new ListNode(c1);
                l1 = l1->next;
                ret = ret->next;
            }
            else{
                ret->next = new ListNode(c2);
                l2 = l2->next;
                ret = ret->next;    
            }
        }
        while(l1){
            int c1 = l1->val;
            ret->next = new ListNode(c1);
            l1 = l1->next;
            ret = ret->next;
        }
        while(l2){
            int c1 = l2->val;
            ret->next = new ListNode(c1);
            l2 = l2->next;
            ret = ret->next;
        }
        return hh->next;
    }
};
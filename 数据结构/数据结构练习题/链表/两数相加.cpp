// https://leetcode-cn.com/problems/add-two-numbers/
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ret = new ListNode(0);
        ListNode* t = ret;
        int carry = 0;
        while(l1 && l2){
            int cur = l1->val + l2->val + carry;
            carry = cur / 10;
            cur = cur % 10;
            t->next = new ListNode(cur);
            t = t->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while(l1){
            int cur = l1->val + carry;
            carry = cur / 10;
            cur = cur % 10;
            t->next = new ListNode(cur);
            t = t->next;
            l1 = l1->next;
        }
        while(l2){
            int cur = l2->val + carry;
            carry = cur / 10;
            cur = cur % 10;
            t->next = new ListNode(cur);
            t = t->next;
            l2 = l2->next;
        }
        while(carry){
            int cur = carry % 10;
            carry /= 10;
            t->next = new ListNode(cur);
            t = t->next;
        }
        return ret->next;
    }
};
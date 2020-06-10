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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* ahead = new ListNode(-1);
        ListNode* h = ahead;
        h->next = head;
        ListNode* q = h->next;
        while(h->next){
            int sum = 0;
            while(q){
                sum += q->val;
                if(sum == 0) break;
                q = q->next;
            }
            if(sum == 0){
                q = q->next;
                h->next = q;
            }
            else{
                h = h->next;
                q = h->next;
            }
        }
        return ahead->next;
    }
};
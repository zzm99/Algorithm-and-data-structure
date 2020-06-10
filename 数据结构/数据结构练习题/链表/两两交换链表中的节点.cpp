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
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next == NULL) return head;
        ListNode* curnext = head->next;
        head->next = swapPairs(curnext->next);
        curnext->next = head;
        return curnext;
    }
};

///////////////////


class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(head==NULL || head->next == NULL) return head;
        ListNode* first = new ListNode(0);
        first->next = head;
        ListNode* p1 = first;
        while(p1->next && p1->next->next){
            ListNode* tmp1 = p1->next; 
            ListNode* tmp2 = p1->next->next;
            tmp1->next = tmp2->next;
            tmp2->next = tmp1;
            p1->next = tmp2;
            p1 = tmp1;
        }
        return first->next;
    }
};
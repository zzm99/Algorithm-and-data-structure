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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int flaga = 0;
        int flagb = 0;
        ListNode* h1 = headA;
        ListNode* h2 = headB;
        while(h1 && h2){
            if(h1 == h2) return h1;
            if(h1->next) h1 = h1->next;
            else{
                if(flaga == 0) h1 = headB, flaga = 1;
                else return NULL;
            }
            if(h2->next) h2 = h2->next;
            else{
                if(flagb == 0) h2 = headA, flagb = 1;
                else return NULL;
            }
        }
        return NULL;
    }
};
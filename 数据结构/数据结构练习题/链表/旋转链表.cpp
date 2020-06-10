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
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL) return head;
        int N = 1;
        ListNode* tail = head;
        while(tail->next) {
            tail = tail->next;
            N++;
        }
        tail->next = head; //!
        k = N - k % N - 1; 
        while(k) {
            head = head -> next;
            k--;
        }
        tail = head; 
        head = head -> next;
        tail -> next = NULL;
        return head;
    }
};
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
    void reorderList(ListNode* head) {
        stack<ListNode*> s;
        ListNode* p = head;
        while(p) {
            s.push(p);
            p = p->next;
        }
        if(s.size() <= 2) return;
        p = head;
        int size = s.size();
        for(int i=0; i<size/2; i++){
            ListNode* next = p->next;
            p->next = s.top();
            s.pop();
            p->next->next = next;
            p = next;
        }
        p->next = NULL;
    }
};

/////////////////

class Solution {
public:
    void reorderList(ListNode* head){
        if(!head){return ;}
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* preNode = nullptr;
        ListNode* p = slow->next;
        slow->next = nullptr;
        while(p){
            ListNode* next = p->next;
            p->next = preNode;
            preNode = p;
            p = next;
        }
        ListNode* res = new ListNode(-1);
        while(preNode){
            res->next = head;
            head = head->next;
            res = res->next;
            res->next = preNode;
            preNode = preNode->next;
            res = res->next;
        }
        res->next = head;
        head = res;
    }
};

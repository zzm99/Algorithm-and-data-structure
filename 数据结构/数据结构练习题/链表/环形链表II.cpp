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
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        int flag = 0;
        while(fast && slow && fast->next){
            fast = fast->next->next;
            slow = slow->next;
            if(fast == slow) {
                flag = 1; break;
            }
        }
        if(flag){
            ListNode* q = head;
            while(fast != q){
                q = q->next;
                fast = fast->next;
            }
            return q;
        }
        return NULL;
    }
};

/*

2⋅distance(tortoise) =distance(hare)
2(F+a) =F+a+b+a
2F+2a =F+2a+b
F =b
​   
 */
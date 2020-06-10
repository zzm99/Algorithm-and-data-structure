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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ret;
        ListNode* t = head;
        while(head){
            int flag = 0;
            t = t->next;
            while(t){
                if(t->val > head->val){
                    ret.push_back(t->val); flag = 1; break;
                }
                t = t->next;
            }
            if(flag == 0) ret.push_back(0);
            head = head->next;
            t = head;
        }
        return ret;
    }
};
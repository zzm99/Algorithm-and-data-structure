// https://leetcode-cn.com/problems/remove-duplicates-from-sorted-list/
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
    ListNode* deleteDuplicates(ListNode* head) {
        map<int, int> ha;
        ListNode* ret = new ListNode(0);
        ListNode* ccc = ret;
        while(head){
            int cval = head->val;
            if(ha.find(cval) == ha.end()){
                ha[cval]++;
                ret->next = new ListNode(cval);
                ret = ret->next;
            }else{
                head = head->next;
            }
        }
        return ccc->next;
    }
};

////////////////////////////////////

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *pi = head;
        while (pi && pi->next) {
            if (pi->val == pi->next->val) {
                ListNode *del = pi->next;
                pi->next = pi->next->next;
                delete del;
            } else {
                pi = pi->next;
            }
        }
        return head;
    }
};
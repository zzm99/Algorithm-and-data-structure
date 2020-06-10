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
    vector<ListNode*> splitListToParts(ListNode* root, int k) {
        int len = 0;
        ListNode* t = root;
        while(t){
            len++; t = t->next;
        }
        int num1 = len / k;
        int num2 = len % k;
        vector<ListNode*> ret(k, NULL);
        ListNode* head = root;
        ListNode* pre = NULL;
        for(int i=0; i<k; i++){
            ret[i] = head;
            int temlen = num2 > 0 ? (num1 + 1) : num1;
            for(int j=0; j<temlen; j++){
                pre = head;
                head = head->next;
            }
            if(pre) pre->next = NULL;
            if(num2) num2--;
        }
        return ret;
    }
};
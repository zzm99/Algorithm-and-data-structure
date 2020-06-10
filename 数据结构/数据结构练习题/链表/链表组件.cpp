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
    int numComponents(ListNode* head, vector<int>& G) {
        int result = 0;
        while(head){
            if(find(G.begin(), G.end(), head->val) != G.end()){
                if(!head->next || find(G.begin(), G.end(), head->next->val) == G.end())
                    result++;
            }
            head = head->next;
        }
        return result;
    }
};
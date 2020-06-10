/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(!head) return NULL;
        else if(!head->next) return new TreeNode(head->val);
        ListNode* pre = head;
        ListNode* p = pre->next;
        ListNode* q = p->next;
        while(q && q->next){
            pre = pre->next;
            p = pre->next;
            q = q->next->next;
        }
        pre->next = NULL;
        TreeNode* root = new TreeNode(p->val);
        root->left = sortedListToBST(head);
        root->right = sortedListToBST(p->next);
        return root;
    }
};
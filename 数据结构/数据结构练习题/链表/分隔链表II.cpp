// 给定一个链表和一个特定值 x，对链表进行分隔，使得所有小于 x 的节点都在大于或等于 x 的节点之前。

// 你应当保留两个分区中每个节点的初始相对位置。

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
    ListNode* partition(ListNode* head, int x) {
        ListNode* l1 = new ListNode(-1);
        ListNode* l2 = new ListNode(-1);
        ListNode* t = head;
        ListNode* t1 = l1;
        ListNode* t2 = l2;
        while(t){
            if(t->val < x){
                t1->next = new ListNode(t->val);
                t1 = t1->next;
            }
            else{
                t2->next = new ListNode(t->val);
                t2 = t2->next;
            }
            t = t->next;
        }
        t1->next = l2->next;
        return l1->next;
    }
};
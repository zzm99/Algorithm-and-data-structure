// 请判断一个链表是否为回文链表。
// O(n) 时间复杂度和 O(1) 空间复杂度
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
    bool isPalindrome(ListNode* head) {
        ListNode *slow = head, *fast = head, *prev = NULL;
        while(fast){
            slow = slow->next;
            fast = fast->next ? fast->next->next : fast->next;
        }
        while(slow){
            ListNode* nextTemp = slow->next;
            slow->next = prev;
            prev = slow;
            slow = nextTemp;
        }
        while(head && prev){
            if(head->val != prev->val){
                return false;
            }
            head = head->next;
            prev = prev->next;
        }
        return true;
    }
};
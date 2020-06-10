// https://leetcode-cn.com/problems/add-two-numbers-ii/

// 给定两个非空链表来代表两个非负整数。数字最高位位于链表开始位置。它们的每个节点只存储单个数字。将这两数相加会返回一个新的链表。

// 你可以假设除了数字 0 之外，这两个数字都不会以零开头。

// 进阶:

// 如果输入链表不能修改该如何处理？换句话说，你不能对列表中的节点进行翻转。

// 示例:

// 输入: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
// 输出: 7 -> 8 -> 0 -> 7
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(!l1) return l2;
        if(!l2) return l1;
        stack<int> s1;
        stack<int> s2;
        while(l1){
            s1.push(l1->val);
            l1 = l1->next;
        }
        while(l2){
            s2.push(l2->val);
            l2 = l2->next;
        }
        ListNode* ret = NULL;
        int carry = 0;
        while(!s1.empty() && !s2.empty()){
            int c1 = s1.top(), c2 = s2.top(); s1.pop(); s2.pop();
            int sum = c1 + c2 + carry;
            carry = sum / 10;
            sum = sum % 10;
            ListNode* rem = new ListNode(sum);
            rem->next = ret;
            ret = rem;
        }
        while(!s1.empty()){
            int c1 = s1.top(); s1.pop(); 
            int sum = c1 + carry;
            carry = sum / 10;
            sum = sum % 10;
            ListNode* rem = new ListNode(sum);
            rem->next = ret;
            ret = rem;
        }
        while(!s2.empty()){
            int c1 = s2.top(); s2.pop(); 
            int sum = c1 + carry;
            carry = sum / 10;
            sum = sum % 10;
            ListNode* rem = new ListNode(sum);
            rem->next = ret;
            ret = rem;
        }
        while(carry){
            int sum = carry;
            carry = sum / 10;
            sum = sum % 10;
            ListNode* rem = new ListNode(sum);
            rem->next = ret;
            ret = rem;
        }
        return ret;
    }
};
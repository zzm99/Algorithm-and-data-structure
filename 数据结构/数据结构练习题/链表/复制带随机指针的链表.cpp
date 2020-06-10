/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return head;
        Node* node = head;
        //1. 将复制节点添加到原节点后面
        while(node != NULL){
            Node* copy = new Node(node->val, NULL, NULL);
            copy->next = node->next;
            node->next = copy;
            node = copy->next;
        }
        //2. 复制random节点
        node = head;
        while(node != NULL){
            if(node->random != NULL){
                node->next->random = node->random->next; // random->next是一个拷贝的节点
            }
            node = node->next->next;
        }
        node = head;
        Node* newHead = head->next;
        Node* newNode = newHead;
        while(node){ // 1->2->3->4
            node->next = node->next->next; // 1->3->4; 2->3->4;
            if(newNode->next) newNode->next = newNode->next->next; // 1->3->4; 2->4;
            node = node->next;  // 3->4;
            newNode = newNode->next; // 4
        }
        return newHead;
    }
};
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/
class Solution {
public:
    vector<Node*> v;
    void dfs(Node* head){
        if(!head) return;
        v.push_back(head);
        dfs(head->child);
        dfs(head->next);
    }
    Node* flatten(Node* head) {
        dfs(head);
        int n = v.size();
        for(int i=0; i<n; i++){
            if(i+1<n) v[i]->next = v[i+1];
            if(i>0) v[i]->prev = v[i-1];
            v[i]->child = NULL;
        }
        return head;
    }  
};
// 普通：
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return root;
        queue<Node*> q;
        q.push(root);
        while(!q.empty()){
            vector<Node*> out;
            int size = q.size();
            for(int i=0; i<size; i++){
                auto temp = q.front();
                q.pop();
                out.push_back(temp);
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            for(int i=0; i<out.size()-1; i++){
                out[i]->next = out[i+1];
            }
        }
        return root;
    }
};

// 进阶： 你只能使用常量级额外空间。
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/
class Solution {
public:
    Node* connect(Node* root) {
        Node* curr = root;
        while(curr){
            Node* dummy = new Node();
            Node* tail = dummy;
            while(curr){
                if(curr->left){
                    tail->next = curr->left;
                    tail = tail->next;
                }
                if(curr->right){
                    tail->next = curr->right;
                    tail = tail->next;
                }
                curr = curr->next;
            }
            curr = dummy->next;
            if(tail == dummy) break;
        }
        return root;
    }
};
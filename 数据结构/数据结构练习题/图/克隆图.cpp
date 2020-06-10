// 给定无向连通图中一个节点的引用，返回该图的深拷贝（克隆）。图中的每个节点都包含它的值 val（Int） 和其邻居的列表（list[Node]）。

// dfs + hash（记录）

/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
class Solution {
public:
    map<Node*, Node*> st;
    Node* cloneGraph(Node* node) {
        Node* ret = new Node(node->val, vector<Node*>());
        st[node] = ret;
        for(auto x : node->neighbors){
            auto p = st.find(x);
            if(p == st.end())
                ret->neighbors.push_back(cloneGraph(x));
            else
                ret->neighbors.push_back(p->second);
        }
        return ret;
    }
};
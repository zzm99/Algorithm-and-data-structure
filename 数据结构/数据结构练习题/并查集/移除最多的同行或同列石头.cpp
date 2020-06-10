// On a 2D plane, we place stones at some integer coordinate points.  Each coordinate point may have at most one stone.

// Now, a move consists of removing a stone that shares a column or row with another stone on the grid.

// What is the largest possible number of moves we can make?

// 题意：

// 移除一个石头的条件是 同行或者同列 有石头

// 要把行或列相同的石头（有传递性）都并在一起，最后最多能move几次就是总的石头的数目减去集合的数目（在每个连通分量里面，最多能移除石子的数量为 连通分量中石子数量 - 1。）

class Solution {
public:
    struct TreeNode{
        int x;
        int y;
        TreeNode* parent;
        TreeNode(int xx, int yy): x(xx), y(yy), parent(this){}
    };

    TreeNode* find(TreeNode* tt){
        TreeNode* p = tt;
        while(p != p->parent){
            p = p->parent;
        }
        return p;
    }

    void Union(TreeNode* t1, TreeNode* t2){
        TreeNode* p1 = find(t1);
        TreeNode* p2 = find(t2);
        if(p1 == p2) return;
        p1->parent = p2;
    }

    int removeStones(vector<vector<int>>& stones) {
        vector<TreeNode*> te;  
        for(auto t: stones) 
            te.push_back(new TreeNode(t[0], t[1]));

        for(int i=0; i<te.size(); i++)
            for(int j=i+1; j<te.size(); j++)
                if(te[i]->x == te[j]->x || te[i]->y == te[j]->y) 
                    Union(te[i], te[j]);

        int ans = 0;
        for(int i=0; i<te.size(); i++)
            if(te[i]->parent == te[i]) ans++;
            
        return stones.size()-ans;
    }
};
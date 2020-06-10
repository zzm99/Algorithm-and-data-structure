// https://leetcode-cn.com/problems/evaluate-division
class Solution {
private:
    class unionSet{
    private:
        unordered_map<string, string> fa;
        unordered_map<string, double> val;

        bool exist(const string& x) { return fa.find(x) != fa.end();}

        void init(const string& x) {
            if (exist(x)) return;
            val[x] = 1;
            fa[x] = x;
        }

        string getFather(const string& x) {
            if (fa[x] == x) return x;
            else {
                string f = getFather(fa[x]);
                val[x] = val[x] * val[fa[x]];
                return fa[x] = f;
            }
        }
    public:
        void merge(const string& a, const string& b, double v) {
            init(a);init(b);
            string aa = getFather(a), bb = getFather(b);
            fa[bb] = aa;
            val[bb] = val[a] * 1.0 / val[b] * v;
        }
        double ask(const string& a, const string& b) {
            if (!exist(a) || !exist(b)) return -1;
            string aa = getFather(a), bb = getFather(b);
            if (aa != bb) return -1;
            return val[b] * 1.0 / val[a]; 
        }
    };
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unionSet u;
        for (int i = 0; i < equations.size(); i++) {
            u.merge(equations[i][0], equations[i][1], values[i]);
        }
        vector<double> ans;
        for (int i = 0; i < queries.size(); i++) {
            ans.push_back(u.ask(queries[i][0], queries[i][1]));
        }
        return ans;
    }
};

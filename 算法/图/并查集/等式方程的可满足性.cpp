// https://leetcode-cn.com/problems/satisfiability-of-equality-equations/
class Solution {
public:
    vector<int> pa;
    void init(){
        pa.resize(26);
        for(int i=0; i<26; i++)
            pa[i] = i;
    }
    int find(int p){
        while(p != pa[p]){
            pa[p] = pa[pa[p]];
            p = pa[p];
        }
        return pa[p];
    }
    void merge(char a, char b){
        int Pa = find(a-'a');
        int Pb = find(b-'a');
        if(Pa != Pb) {
            pa[Pb] = Pa;
        }
    }
    bool connect(char a, char b){
        return find(a-'a') == find(b-'a');
    }
    bool equationsPossible(vector<string>& equations) {
        init();
        for(auto& eq: equations) {
            if(eq[1] == '=') {
                merge(eq[0], eq[3]);
            }
        }
        for(auto& eq: equations) {
            if(eq[1] == '!'){
                if(connect(eq[0], eq[3])) 
                    return false;
            }
        }
        return true;
    }
};
class CombinationIterator {
public:
    queue<string> cot;

    void helper(string characters, int curlen, int len, string curstr, int idx){
        if(len == 0) return;
        if(curlen > len) return;
        if(curlen == len){
            cot.push(curstr);
            return;
        }
        for(int i=idx; i<characters.size(); i++){
            string cstr = curstr + characters[i];
            helper(characters, curlen+1, len, cstr, i+1);
        }
    }
    
    CombinationIterator(string characters, int combinationLength) {
        string cur = "";
        helper(characters, 0, combinationLength, cur, 0);
    }
    
    string next() {
        string ret = cot.front();
        cot.pop();
        return ret;
    }
    
    bool hasNext() {
        return cot.size() != 0;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
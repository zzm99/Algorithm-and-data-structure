class Solution {
public:
    bool isValidSerialization(string preorder) {
        int degree = 1;
        string tmp;
        stringstream ss;
        ss << preorder;
        while(getline(ss, tmp, ',')){
            degree--;
            if(degree<0) return false;
            if(tmp[0]!='#') degree+=2;
        }
        return degree == 0;
    }
};
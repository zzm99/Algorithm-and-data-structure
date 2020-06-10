// 给定 s = "[123,[456,[789]]]",

// 返回一个 NestedInteger 对象包含一个有两个元素的嵌套列表：

// 1. 一个 integer 包含值 123
// 2. 一个包含两个元素的嵌套列表：
//     i.  一个 integer 包含值 456
//     ii. 一个包含一个元素的嵌套列表
//          a. 一个 integer 包含值 789

/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
public:
    NestedInteger deserialize(string s) {
        if(s.empty()) return NestedInteger();
        if(s[0]!='[') return NestedInteger(stoi(s));
        if(s.size() <= 2) return NestedInteger();
        NestedInteger res;
        int start = 1, cnt = 0;
        for(int i=1; i<s.size(); i++){
            if(cnt == 0 && (s[i] == ',' || i == s.size()-1)){
                res.add(deserialize(s.substr(start, i-start)));
                start = i+1;
            }
            else if(s[i] == '[') cnt++;
            else if(s[i] == ']') cnt--; 
        }
        return res;
    }
};
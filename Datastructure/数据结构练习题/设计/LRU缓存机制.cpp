// https://leetcode-cn.com/problems/lru-cache/
class LRUCache {
public:
    int cap;
    unordered_map<int, list<pair<int, int>>::iterator> mp;
    list<pair<int, int>> mylist;

    LRUCache(int capacity) {
        this->cap = capacity;
    }
    
    int get(int key) {
        auto it = mp.find(key);
        if(it == mp.end()) return -1;
        int val = it->second->second;
        mylist.erase(it->second);
        mylist.push_front(make_pair(key, val));
        mp[key] = mylist.begin();
        return mylist.begin()->second;
    }
    
    void put(int key, int value) {
        auto it = mp.find(key);
        if(it != mp.end()) mylist.erase(it->second);
        mylist.push_front(make_pair(key, value));
        mp[key] = mylist.begin();
        if(mylist.size() > cap){
            int key = mylist.back().first;
            mp.erase(key);
            mylist.pop_back();
        }
    }
};
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> count(26, 0);
        for(auto c: tasks){
            count[c-'A']++;
        }
        sort(count.begin(), count.end());
        int max = count[25];
        int maxcount = 1;
        int i = 24;
        while(count[i] == max){
            maxcount++;
            i--;
        }
        int ret = (max-1)*(n+1)+maxcount;
        return ret < tasks.size() ? tasks.size() : ret;
    }
};
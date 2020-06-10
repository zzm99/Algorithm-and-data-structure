class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        for(auto& p: prerequisites){
            indegree[p[0]]++;
        }
        vector<int> ret;
        queue<int> q;
        int cnt = 0;
        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        while(!q.empty()){
            int cur = q.front(); q.pop();
            ret.push_back(cur);
            cnt++;
            for(int i=0; i<prerequisites.size(); i++){
                if(cur == prerequisites[i][1]){
                    indegree[prerequisites[i][0]]--;
                    if(indegree[prerequisites[i][0]] == 0)
                        q.push(prerequisites[i][0]);
                }
            }
        }
        if(cnt == numCourses)
            return ret;
        else
            return {};
    }
};
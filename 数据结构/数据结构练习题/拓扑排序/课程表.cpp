class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        for(auto a: prerequisites){
            indegree[a[0]]++;
        }
        queue<int> q;
        for(int i=0; i<numCourses; i++){
            if(indegree[i] == 0)
                q.push(i);
        }
        int cnt = 0;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            cnt++;
            for(int i=0; i<prerequisites.size(); i++){
                if(prerequisites[i][1] == front){
                    indegree[prerequisites[i][0]]--;
                    if(indegree[prerequisites[i][0]] == 0)
                        q.push(prerequisites[i][0]);
                }
            }
        }
        return cnt == numCourses;
    }
};
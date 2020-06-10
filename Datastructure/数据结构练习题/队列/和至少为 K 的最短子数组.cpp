class Solution {
public:
    int shortestSubarray(vector<int>& A, int K) {
        int n = A.size();
        vector<int> sum(n+1, 0);
        for(int i=0; i<n; i++)
            sum[i+1] = sum[i]+A[i];
        deque<int> de;
        int j=0; 
        int res = n+1;
        while(j<=n){
            while(!de.empty() && sum[j]<=sum[de.back()]) de.pop_back();
            while(!de.empty() && sum[j]-sum[de.front()]>=K){
                res = min(res, j-de.front());
                de.pop_front();
            }
            de.push_back(j);
            j++;
        }
        if(res == n+1) return -1;
        else return res;
    }
};
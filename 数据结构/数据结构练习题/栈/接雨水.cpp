class Solution {
public:
    int trap(vector<int>& height) {
        int ret = 0;
        int n = height.size();
        vector<int> l(n), r(n);
        for(int i=1; i<n; i++) l[i] = max(l[i-1], height[i-1]);
        for(int i=n-2; i>=0; i--) r[i] = max(r[i+1], height[i+1]);
        for(int i=0; i<n; i++){
            int tmp = min(l[i], r[i]);
            ret += max(0, tmp-height[i]);
        }
        return ret;
    }
};
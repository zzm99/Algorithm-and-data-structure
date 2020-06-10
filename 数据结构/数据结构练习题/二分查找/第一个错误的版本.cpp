// 假设你有 n 个版本 [1, 2, ..., n]，你想找出导致之后所有版本出错的第一个错误的版本。

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int lo = 1;
        int hi = n;
        while(lo < hi){
            int mid = lo + (hi-lo)/2;
            if(isBadVersion(mid)) hi = mid;
            else lo = mid+1;
        }
        return hi;
    }
};
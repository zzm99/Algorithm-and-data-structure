class Solution {
public:
    int mySqrt(int x) {
        int l = 0;
        int r =  x;
        while(l <= r){
            long long mid = (l+r)/2;
            if(mid *mid == x) return mid;
            else if(mid*mid < x) l = mid+1;
            else r = mid-1; 
        }
        return r;
    }
};


/////////////////

class Solution {
public:
    int mySqrt(int x) {
        long long xx =x;
        while(xx * xx > x){
            xx = (xx + x/xx)/2;
        }
        return (int)xx;
    }
};
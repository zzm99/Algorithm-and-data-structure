class MedianFinder {
public:
    priority_queue<int> lo; // 最大堆
    priority_queue<int, vector<int>, greater<int>> hi; // 最小堆

    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        lo.push(num);
        hi.push(lo.top());
        lo.pop();
        if(lo.size() < hi.size()){
            lo.push(hi.top());
            hi.pop();
        }
    }
    
    double findMedian() {
        return lo.size() > hi.size() ? lo.top(): (lo.top() + hi.top())/2.0;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */
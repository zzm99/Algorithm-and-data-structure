class MyStack {
public:
    queue<int> q1;
    queue<int> q2;

    MyStack() {}

    void push(int x) {
        q1.push(x);
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
    }
    
    int pop() {
        int cur = q2.front();
        q2.pop();
        return cur;
    }
    
    int top() {
        return  q2.front();
    }
    
    bool empty() {
        return q2.empty();
    }
};
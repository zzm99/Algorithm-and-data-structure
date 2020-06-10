class MyCircularQueue {
public:
    vector<int> qq;
    int size;
    int front;
    int rear;
    /** Initialize your data structure here. Set the size of the queue to be k. */
    MyCircularQueue(int k) {
        size = k+1;
        qq.resize(size);
        front = rear = 0;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if(isFull()) return false;
        qq[rear++] = value;
        rear %= size;
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if(isEmpty()) return false;
        front++;
        front %= size;
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if(isEmpty()) return -1;
        return qq[front];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if(isEmpty()) return -1;
        if(rear == 0) return qq[size-1];
        else return qq[rear-1];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        return front == rear;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        return front == (rear+1)%size;
    }
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */
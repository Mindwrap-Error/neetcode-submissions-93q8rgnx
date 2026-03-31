class MyQueue {
private:
    stack<int> enqueue, dequeue;
public:
    MyQueue() {
    }
    
    void push(int x) {
        enqueue.push(x);
    }
    
    int pop() {
        if(dequeue.empty())
        {
            while(!enqueue.empty())
            {
                dequeue.push(enqueue.top());
                enqueue.pop();
            }
        }
        int tmp = dequeue.top();
        dequeue.pop();
        return tmp;
    }
    
    int peek() {
        if(dequeue.empty())
        {
            while(!enqueue.empty())
            {
                dequeue.push(enqueue.top());
                enqueue.pop();
            }
        }
        return dequeue.top();
    }
    
    bool empty() {
        return dequeue.empty() && enqueue.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
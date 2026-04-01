class MinStack {
public:
    stack<int> stk;
    stack<int> minStk;

    MinStack() {
        
    }
    
    void push(int val) {
        if(stk.empty())
        {
            stk.push(val);
            minStk.push(val);
        }
        else
        {
            stk.push(val);
            if(val < minStk.top())
            {
                minStk.push(val);
            }
            else
            {
                minStk.push(minStk.top());
            }
        }
    }
    
    void pop() {
        stk.pop();
        minStk.pop();
    }
    
    int top() {
        return stk.top();
    }
    
    int getMin() {
        return minStk.top();
    }
};

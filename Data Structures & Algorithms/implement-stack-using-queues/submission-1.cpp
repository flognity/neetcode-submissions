class MyStack {
private:
    std::queue<int> q;
public:
    MyStack() {
        
    }
    
    void push(int x) {
        // push will push to the last element of the stack;
        // in our queue that's the front;
        // push would put it at the back

        // we need to rebuild a the queue with the newest element first
        std::queue<int> tmp;
        tmp.push(x);
        while (q.size() > 0)
        {
            tmp.push(q.front());
            q.pop();
        }

        // rebuild the queue
        while (tmp.size() > 0)
        {
            q.push(tmp.front());
            tmp.pop();
        }
    }
    
    int pop() {
        // since all pushes made the queue a stack, we can use normal operation now
        int retVal = q.front();
        q.pop();
        return retVal;
    }
    
    int top() {
         // since all pushes made the queue a stack, we can use normal operation now
        return q.front();
    }
    
    bool empty() {
        return q.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
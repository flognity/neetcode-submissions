class MinStack {
public:
    MinStack() {
    }
    
    void push(int val) {
        m_stack.push_back(val);
    }
    
    void pop() {
        m_stack.pop_back();
    }
    
    int top() {
        return m_stack.back();
    }
    
    int getMin() {
        return *std::min_element(m_stack.begin(), m_stack.end());
    }
private:
    std::vector<int> m_stack;
};

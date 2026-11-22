class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        m_k = k;
        for(int &n: nums)
            m_maxHeap.push(n);
    }
    
    int add(int val) {
        // add the new value to the heap
        m_maxHeap.push(val);

        // pop k-times but remember the values in order to push them back
        std::stack<int> s;
        for(int i = 0; i < m_k - 1 && m_maxHeap.size() > 0; ++i) {
            // remember this value by storing it in the stack
            s.push(m_maxHeap.top());
            // remove the largest number;
            m_maxHeap.pop();
        }

        // the top of the heap should now be the k-th largest element
        int retValue = m_maxHeap.top();

        // restore the heap
        int stackSize = s.size();
        for(size_t i = 0; i < stackSize; ++i) {
            m_maxHeap.push(s.top());
            s.pop();
        }

        return retValue;
    }

private:
    std::priority_queue<int, vector<int>, std::less<int>> m_maxHeap;
    int m_k;
};

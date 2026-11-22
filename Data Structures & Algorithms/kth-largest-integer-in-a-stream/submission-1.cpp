class KthLargest {
public:
    KthLargest(int k, vector<int>& nums) {
        m_k = k;
        for(int &n: nums) {
            m_minHeap.push(n);
            if(m_minHeap.size() > m_k)
                m_minHeap.pop();
        }
    }
    
    int add(int val) {
        // add the new value to the heap
        m_minHeap.push(val);

        // pop the smallest element to maintain the k-th largest in size
        if(m_minHeap.size() > m_k)
            m_minHeap.pop();

        return m_minHeap.top();
    }

private:
    std::priority_queue<int, vector<int>, std::greater<int>> m_minHeap;
    int m_k;
};

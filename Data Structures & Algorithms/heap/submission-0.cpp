class MinHeap {
    // NOTES: 
    // idx 0 is a dummy placeholder for the math to work out
    // left child idx  = 2 * 1
    // right child idx = 2 * 1 + 1
    // parent node     = i / 2
public:
    MinHeap() {
        heap.push_back(-1);
    }

    void push(int val) {
        heap.push_back(val);
        // percolate up
        int i = (int)heap.size() - 1;
        while (i > 1 && heap[i] < heap[i / 2]) {
            std::swap(heap[i], heap[i / 2]);
            i = i / 2;
        }
    }

    int pop() {
        // get the top
        int retVal = top();
        if(heap.size() ==  1)
            return retVal;
        if(heap.size() == 2) {
            heap.pop_back();
            return retVal;
        }

        // replace the top element with the last one
        heap[1] = heap[heap.size() - 1];
        heap.pop_back();
        // now percolate down
        percolateDown(1);

        return retVal;
    }

    int top() {
        if(heap.size() > 1)
            return heap[1];
        else
            return heap[0];
    }

    void heapify(const vector<int>& arr) {
        if(arr.size() < 1)
            return;
        // copy the data
        heap = arr;
        // move the first element to the end
        heap.push_back(arr[0]);
        // restore default placeholder
        heap[0] = -1;

        // get the frist non-leaf node
        int i = ((int)heap.size() - 1) / 2;
        while(i > 0) {
            percolateDown(i);
            --i;
        }

    }
private:
    void percolateDown(int i) {
        while ( 2 * i < heap.size()) {
            int lIdx = 2 * i;
            int rIdx = 2 * i + 1;
            // check right child first
            if( rIdx < heap.size()       // right child exists
            &&  heap[rIdx] < heap[lIdx]  // right child is smaller
            &&  heap[i] > heap[rIdx] ) { // current idx is larger
                // swap element i with rIdx
                std::swap(heap[i], heap[rIdx]);
                i = rIdx;
            }
            // check left child
            else if(heap[i] > heap[2 * i]) {
                // swap element i with lIdx
                std::swap(heap[i], heap[lIdx]);
                i = lIdx;
            }
            else {
                break;
            }
        }
    }

    std::vector<int> heap;
};

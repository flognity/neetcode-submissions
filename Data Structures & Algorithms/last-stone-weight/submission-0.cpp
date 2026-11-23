class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size() < 1)
            return 0;

        std::make_heap(stones.begin(), stones.end());

        while(stones.size() > 1) {
            // pop the 2 heaviest stones
            std::pop_heap(stones.begin(), stones.end());
            int stone1 = stones.back();
            stones.pop_back();

            std::pop_heap(stones.begin(), stones.end());
            int stone2 = stones.back();
            stones.pop_back();

            if(stone2 < stone1) {
                stone1 -= stone2;
                // add back to the heap
                stones.push_back(stone1);
                // heapify
                std::push_heap(stones.begin(), stones.end());
            }
        }

        if(stones.size() > 0)
            return stones[0];

        return 0;
    }
};

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size() < 1)
            return 0;

        std::priority_queue<int, vector<int>, std::less<int>> maxQ(stones.begin(), stones.end());

        while(maxQ.size() > 1) {
            // pop the 2 heaviest stones
            int stone1 = maxQ.top();
            maxQ.pop();

            int stone2 = maxQ.top();
            maxQ.pop();

            if(stone2 < stone1) {
                stone1 -= stone2;
                // add back to the heap
                maxQ.push(stone1);
            }
        }

        if(maxQ.size() > 0)
            return maxQ.top();
        else
            return 0;
    }
};

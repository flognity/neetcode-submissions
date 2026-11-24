class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        if(nums.size() < 1)
            return 0;
        if(nums.size() == 1)
            return nums[0];

        // construct a min heap in O(n)
        std::make_heap(nums.begin(), nums.end(), std::greater<int>{});

        // now pop until we only have k elements
        while(nums.size() > k) {
            std::pop_heap(nums.begin(), nums.end(), std::greater<int>{});
            nums.pop_back();
        }

        return nums.front();
    }
};

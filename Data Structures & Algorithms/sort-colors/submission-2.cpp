class Solution {
public:
    void sortColors(vector<int>& nums) {
        // Challenge: only use one loop
        if (nums.size() < 2)
            return;

        // keep track of the left, which will be all 0
        // keep track of the right (reverse order), which will be all 2
        int left  = 0;
        int right = (int)nums.size() - 1;

        for(int i = 0; i <= right; ++i) {
            if(nums[i] == 0) {
                std::swap(nums[i], nums[left]);
                ++left;
            }
            if(nums[i] == 2) {
                std::swap(nums[i], nums[right]);
                --right;
                // now that numbers have swapped with the end, we need to check i again,
                // so, cancel out the loops increment
                --i;
            }
        }
    }
};
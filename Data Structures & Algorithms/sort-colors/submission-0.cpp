class Solution {
public:
    void sortColors(vector<int>& nums) {
        // only 3 possible values and thus prime candidate for bucket sort
        if (nums.size() < 2)
            return;

        int numColors = 3;
        // count each occurrence
        vector<int> count(numColors, 0);
        for(int i = 0; i < nums.size(); ++i) {
            ++(count[nums[i]]);
        }

        // assemble the output
        int pos = 0;
        for(int color = 0; color < numColors; ++color) {
            for(int i = 0; i < count[color]; i++) {
                nums[pos] = color;
                ++pos;
            }
        }
    }
};
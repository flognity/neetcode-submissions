class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> index(2);
        if(nums.size() < 2)
            return index;

        for (size_t i = 0; i < nums.size(); ++i) {
            for(size_t j = i + 1; j < nums.size(); ++j)
            {
                if((nums.at(i) + nums.at(j)) == target) {
                    index.at(0) = i;
                    index.at(1) = j;
                    return index;
                }
            }
        }

        return index;
    }
};

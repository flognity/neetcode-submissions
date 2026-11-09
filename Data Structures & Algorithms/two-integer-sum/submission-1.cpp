class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if(nums.size() < 2)
            return {};

        for (int i = 0; i < (int)nums.size(); ++i)
            for(int j = i + 1; j < (int)nums.size(); ++j)
                if((nums.at(i) + nums.at(j)) == target)
                    return {i, j};

        return {};
    }
};
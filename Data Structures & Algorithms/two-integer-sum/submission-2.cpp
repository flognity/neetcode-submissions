class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        if (nums.size() < 2)
            return {};

        std::unordered_map<int, int> map = {};
        int diff;

        for (int i = 0; i < (int)nums.size(); ++i) {
            diff = target - nums.at(i);
            if (map.contains(diff))
                return {map[diff], i};

            map[nums.at(i)] = i;
        }

        return {};
    }
};
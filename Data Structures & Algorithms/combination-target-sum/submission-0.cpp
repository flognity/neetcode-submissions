class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<vector<int>> out = {};
        int size = (int)nums.size();
        if(size < 1)
            return out;

        vector<int> combo = {};
        // helper function for a depth firt search
        auto fnDfs = [&](auto &self, int i, int sum) {
            if(i >= size || sum > target) {
                return;
            }

            if(sum == target) {
                out.push_back(combo);
                return;
            }

            sum += nums[i];
            combo.push_back(nums[i]);

            // branch 1: use the same number again
            self(self, i, sum);
                
            // back track
            combo.pop_back();
            sum -= nums[i];

            // branch 2: use the next number
            self(self, i + 1, sum);
        };

        fnDfs(fnDfs, 0, 0);
        return out;
    }
};

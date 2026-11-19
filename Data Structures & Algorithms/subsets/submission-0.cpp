class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> out;
        if(nums.size() < 1)
            return out;

        // first element is the empty set
        vector<int> currSet = {};

        // helper function for recursive depth first search
        auto fnDfs = [&](auto &self, int i) {
            // base case (leaf node, so add the set)
            if(i >= nums.size()) {
                out.push_back(currSet);
                return;
            }

            // solutions with nums[i]
            currSet.push_back(nums[i]);
            self(self, i+1);

            // solutions without nums[i]
            currSet.pop_back();
            self(self, i+1);
        };
        
        fnDfs(fnDfs, 0);
        return out;   
    }
};

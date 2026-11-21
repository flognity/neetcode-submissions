class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> out = {};
        if(nums.size() < 1)
            return out;

        // unordered map to count each occurrence;
        // ordering doesn't work here because we don't want to order by the key;
        // we need to order by value
        std::unordered_map<int, int> frequency = {};
        for(auto &n: nums) {
            ++frequency[n];
        }

        // now create a vector whre the index is the frequency and the numbers are values
        vector<vector<int>> topNums(nums.size() + 1);
        for(auto [n, f]: frequency) {
            topNums[f].push_back(n);
        }

        // iterate over the vector backwards
        for(int i = (int)topNums.size() - 1 ; i >= 0 && (int)out.size() < k; --i) {
            for(size_t j = 0; j < topNums[i].size() && (int)out.size() < k; ++j)
                out.push_back(topNums[i][j]);
        }

        return out;
    }
};

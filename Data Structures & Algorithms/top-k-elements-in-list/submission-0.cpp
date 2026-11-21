class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> out = {};
        if(nums.size() < 1)
            return out;

        // unordered map to count each occurance;
        // ordering doesn't work here because we don't want to order by the key;
        // we need to order by value
        std::unordered_map<int, int> frequency = {};
        for(auto &n: nums) {
            ++frequency[n];
        }

        // order the map by value
        vector<std::pair<int, int>> ordered(frequency.begin(), frequency.end());
        std::sort(ordered.begin(), ordered.end(), [](auto &a, auto &b) {
            return a.second > b.second;
        });

        // iterate over the sorted vector
        for(size_t i = 0; i < ordered.size() && (int)out.size() < k; ++i) {
            out.push_back(ordered[i].first);
        }

        return out;
    }
};

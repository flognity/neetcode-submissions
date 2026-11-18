class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // Group in a map. A sorted anagram is always the same and thus can be a key
        unordered_map<string, vector<string>> groups;
        for (const string& s : strs) {
            string key = s;
            sort(key.begin(), key.end());
            groups[key].push_back(s);
        }

        // Construct the output vector from the map
        vector<vector<string>> out;
        for (auto& [key, group] : groups) {
            out.push_back(move(group));
        }

        return out;
    }
};

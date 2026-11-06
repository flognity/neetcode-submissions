class Solution {
public:
    bool isAnagram(string s, string t) {
        // boundary check: both strings must be equal in length
        if(t.size() != s.size())
            return false;

        // the constraint is that the algorithm must be O(m+n)
        // looping over both strings would be O(n^2)
        // thus, a different approach is needed

        // keep track of each character in a map
        // increment count of each letter of one string
        // decrement count of each letter of the other string
        std::map<char, int> counts;
        for(size_t i = 0; i < s.size(); ++i) {
            counts[s[i]]++;
            counts[t[i]]--;
        }

        for(auto [c, count]: counts) {
            // positive or negative values violate anagram condition
            if (count != 0)
                return false;
        }
        return true;
    }
};

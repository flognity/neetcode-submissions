// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };
class Solution {
public:
    vector<vector<Pair>> insertionSort(vector<Pair>& pairs) {
        // define the output
        vector<vector<Pair>> out;

        // empty check
        if (pairs.empty()) {
            return out;
        }

        // first entry is the unsorted vector
        out.push_back(pairs);
        
        // sort the vector and save each iteration to out
        int j;
        for (int i = 1; i < (int)pairs.size(); ++i) {
            j = i - 1;
            while (j >= 0 && pairs[j + 1].key < pairs[j].key) {
                Pair tmp = pairs[j];
                pairs[j] = pairs[j + 1];
                pairs[j + 1] = tmp;
                --j;
            }

            // keep track of this iteration for the output
            out.push_back(pairs);
        }

        return out;
    }
};

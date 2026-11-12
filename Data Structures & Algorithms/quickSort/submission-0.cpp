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
    vector<Pair> quickSort(vector<Pair>& pairs) {
        if(pairs.size() < 2)
            return pairs;

        quickSortHelper(pairs, 0, pairs.size() - 1);
        return pairs;
    }

    void quickSortHelper(vector<Pair>& pairs, int l, int r) {
        if(r - l <= 0)
            return;

        // partition the array in left and right
        Pair pivot = pairs[r];
        int left = l;
        for(int i = l; i < r; ++i) {
            if(pairs[i].key < pivot.key) {
                // swap the entries
                Pair tmp    = pairs[left];
                pairs[left] = pairs[i];
                pairs[i]    = tmp;
                ++left;
            }
        }
        // the pivot belongs between the 2 split sides
        pairs[r]    = pairs[left];
        pairs[left] = pivot;

        // sort the left
        quickSortHelper(pairs, l, left - 1);
        // sort the right
        quickSortHelper(pairs, left + 1, r);
    }

};

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
    vector<Pair> mergeSort(vector<Pair>& pairs) {
        // check the base case
        int size = pairs.size();   
        if(size <= 1)
            return pairs;
        
        // calculate mid-point
        int m = (int)(size / 2);
        vector<Pair> left ( pairs.begin()    , pairs.begin() + m );
        vector<Pair> right( pairs.begin() + m, pairs.end()       );
        // sort the sub-arrays
        mergeSort(left);
        mergeSort(right);

        // merge the 2 sorted arrays
        int l = 0;
        int r = 0;
        while(l+r < size) {
            if (l < left.size() 
            && (r >= right.size() || left[l].key <= right[r].key)) {
                pairs[l+r] = left[l];
                ++l;
            }
            else if (r < right.size()) {
                pairs[l+r] = right[r];
                ++r;
            }
            else {
                break;
            }
        }

        return pairs;
    }
};

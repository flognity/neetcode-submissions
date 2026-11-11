class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int l = 0;
        int r = 0;
        while (l+r < m+n) {
            if (l < m 
            && (r >= n || nums1[l+r] <= nums2[r])) {
                // everything in nums1 stays as is
                ++l;
            } else {
                // everything in nums1 needs to shift right
                int pos = m+n - 1;
                while(pos > l+r) {
                    nums1[pos] = nums1[pos-1];
                    --pos;
                }
                // assign the right value in the now empty spot
                nums1[l+r] =  nums2[r];
                ++r;
            }
        }
    }
};
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // return the number of items that are not equal to val
        // nums should only contain the remaining elements (not equal to val) at the beginning
        int valCount = nums.size(); // start with number of elements
        for (size_t i = nums.size(); i > 0; i--)
        {
            if (nums.at(i - 1) == val)
            {
                // decrement every time we find val
                valCount--;
                // shift the vector
                for (size_t j = i - 1 ; j < (nums.size() - 1); j++)
                {
                    nums.at(j) = nums.at(j + 1);
                }
            }
        }
        return valCount;
    }
};
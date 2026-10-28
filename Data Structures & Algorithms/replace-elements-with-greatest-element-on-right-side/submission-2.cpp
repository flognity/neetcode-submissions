class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        // Task: replace every element with the greatest element to the right
        // Result: sorted array from largest to smalles element
        // Approach: iterate from right to left, keeping track of the max so far
        int currentMax = -1;
        vector<int> outArr = arr;
        for (int idx = static_cast<int>(arr.size()) - 1; idx >= 0; idx--)
        {
            // fill the out array backwards
            outArr.at(idx) = currentMax;

            // keep track of current max
            if(arr.at(idx) > currentMax)
            {
                currentMax = arr.at(idx);
            }
        }

        return outArr;
    }
};
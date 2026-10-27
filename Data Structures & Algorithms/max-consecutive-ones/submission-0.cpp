class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int highestCount = 0;
        for (size_t i = 0; i < nums.size(); i++)
        {
            if (nums[i] == 1)
            { 
                count++;
                if(highestCount < count)
                    highestCount = count;
            }
            else
            {
                count = 0;
            }

        }
        return highestCount;
    }
};
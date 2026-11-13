class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if(matrix.size() < 1)
            return false;

        int rowSize = (int)matrix.size();
        int colSize = (int)matrix[0].size();
        int matrixSize = colSize * rowSize;

        int l = 0;
        int r = matrixSize - 1;
        while (l <= r) {
            int mid = (r+l) / 2;
            // calculate the index of the mind-point
            int i = (int)(mid / colSize);
            int j = mid % colSize;

            if(target < matrix[i][j])
                r = mid - 1;
            else if (target > matrix[i][j])
                l = mid + 1;
            else
                return true;
        }

        return false;
    }
};

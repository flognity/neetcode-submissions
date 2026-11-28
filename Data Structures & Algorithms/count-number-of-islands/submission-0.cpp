class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int rowSize = grid.size();
        int colSize = grid[0].size();

        auto fnDfs = [&](auto &self, int row, int col, std::set<std::pair<int, int>> &visited) {
            // base case: out of bounds or already visited
            if( row < 0 || col < 0
            ||  row >= rowSize || col >= colSize
            ||  visited.count({row, col}) > 0) {
                return 0;
            }
            // base case: water
            if (grid[row][col] == '0') {
                return 0;
            }

            // if we reach this, we will be on land
            visited.insert({row, col});

            self(self, row + 1, col    , visited);
            self(self, row - 1, col    , visited);
            self(self, row    , col + 1, visited);
            self(self, row    , col - 1, visited);

            // we have explored the island
            return 1;
        };

        std::set<std::pair<int, int>> visited = {};
        int islandCount = 0;
        for (int row = 0; row < rowSize; ++row) {
            for (int col = 0; col < colSize; ++col) {
                islandCount += fnDfs(fnDfs, row, col, visited);
            }
        }

        return islandCount;
    }
};

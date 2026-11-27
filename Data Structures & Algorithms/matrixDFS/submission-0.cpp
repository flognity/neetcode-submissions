class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        int rowSize = grid.size();
        int colSize = grid[0].size();

        auto fnDfs = [&](auto &self, int r, int c, std::set<std::pair<int, int>> &visited) {
            // base case: out of bounds or already visited or rock
            if( r < 0 || c < 0
            ||  r >= rowSize || c >= colSize
            ||  grid[r][c] == 1
            ||  visited.count({r, c}) > 0) {
                return 0;
            }
            // base case: reached the end
            if( r == rowSize - 1 && c == colSize - 1) {
                return 1;
            }

            // mark path as visited
            visited.insert({r, c});

            int count = 0;
            count += self(self, r + 1, c    , visited);
            count += self(self, r - 1, c    , visited);
            count += self(self, r    , c + 1, visited);
            count += self(self, r    , c - 1, visited);

            // backtrack
            visited.erase({r, c});
            return count;
        };

        std::set<std::pair<int, int>> visited = {};
        return fnDfs(fnDfs, 0, 0, visited);
    }
};

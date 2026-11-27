class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int rowSize = (int)image.size();
        int colSize = (int)image[0].size();
        int key = image[sr][sc];

        auto fnDfs = [&](auto &self, int r, int c, 
                         std::set<std::pair<int, int>> &visited) {
            // base case: out of bounds or already visited
            if( r < 0 || c < 0 
            ||  r >= rowSize || c >= colSize
            ||  visited.count({r, c})) {
                return;
            }
            // base case: reach an irrelevant position
            if(image[r][c] != key) {
                return;
            }

            // makr this position as visited, so we won't come here again
            visited.insert({r, c});
            image[r][c] = color;

            self(self, r + 1, c    , visited);
            self(self, r - 1, c    , visited);
            self(self, r    , c + 1, visited);
            self(self, r    , c - 1, visited);

            // backtrack
            visited.erase({r, c});
            return;
        };

        std::set<std::pair<int, int>> visited = {};
        fnDfs(fnDfs, sr, sc, visited);
        return image;
    }
};
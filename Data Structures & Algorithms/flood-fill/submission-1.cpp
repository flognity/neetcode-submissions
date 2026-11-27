class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int key = image[sr][sc];
        // check if there is anything to do here
        if (key == color)
            return image;

        int rowSize = (int)image.size();
        int colSize = (int)image[0].size();

        auto fnDfs = [&](auto &self, int r, int c) {
            // base case: out of bounds or already visited
            if( r < 0 || c < 0 
            ||  r >= rowSize || c >= colSize) {
                return;
            }
            // base case: reach an irrelevant position
            if(image[r][c] != key) {
                return;
            }

            // fill this position with the color
            image[r][c] = color;

            self(self, r + 1, c    );
            self(self, r - 1, c    );
            self(self, r    , c + 1);
            self(self, r    , c - 1);
        };

        fnDfs(fnDfs, sr, sc);
        return image;
    }
};
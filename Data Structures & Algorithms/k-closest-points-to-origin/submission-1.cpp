class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        if(points.size() <= 1 || k > points.size())
            return points;

        vector<int> refPoint = {0, 0};
        // calculate the distance to the given point and save the index
        // first entry is the index, second entry the distance
        vector<std::pair<int, float>> distVec;
        for(int i = 0; i < (int)points.size(); ++i) {
            float distance = std::sqrt( std::pow(points[i][0] - refPoint[0], 2) 
                                    + std::pow(points[i][1] - refPoint[1], 2));

            std::pair<int, float> distPair = {i, distance};
            distVec.push_back(distPair);
        }

        // now sort the distVec by the second entry of each pair
        std::sort(distVec.begin(), distVec.end(), 
            [](std::pair<int, float> a, std::pair<int, float> b) 
                {
                    return a.second < b.second;
                });

        std::set<vector<int>> uniquePoints = {};
        int i = 0;
        while((int)uniquePoints.size() < k && i < (int)distVec.size()) {
            uniquePoints.insert(points[distVec[i].first]);
            ++i;
        }

        vector<vector<int>> retPoints(uniquePoints.begin(), uniquePoints.end());
        return retPoints;
    }
};

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int numPiles = (int)piles.size();
        if(numPiles < 1 || h < 1 || numPiles > h)
            return 0;
        
        if(numPiles == 1) {
            // round up to the closest full integer
            return roundUp(piles[0], h);
        }

        // At most the maximum element of the vector is the fastest potential speed.
        // Do a binary search to match or beat the hours in regards to time needed.

        int slowestSpeed = *std::max_element(piles.begin(), piles.end());

        int r = slowestSpeed;
        int l = 1;
        
        while(l <= r) {
            int mid = l + (int)((r - l) / 2);
            long long time = timeNeeded(piles, mid);
            if (time > h) {
                // eat faster
                l = mid + 1;
            } else if (time <= h) {
                // We have found a valid speed.
                // Check if this is better than the best so far
                if(mid < slowestSpeed) {
                    slowestSpeed = mid;
                }

                // try eating slightly slower
                r = mid - 1;
            }
        }
        
        return slowestSpeed;

    }

    long long timeNeeded(vector<int>& piles, int speed) {
        long long timeNeeded = 0;
        for(int &pile: piles) {
            timeNeeded += roundUp(pile, speed);
        }
        return timeNeeded;
    }

    int roundUp(int bananas, int speed) {
        return (int)(bananas / speed) + (bananas % speed != 0);
    }

};

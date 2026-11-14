/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        if(n < 2)
            return n;

        int l = 1;
        int r = n;
        while (l <= r) {
            int mid = l + (r - l) / 2;
            int res = guess(mid);
            if(res < 0) {
                // mid is too large
                r = mid - 1;
            } else if (res > 0) {
                // mid is too small
                l = mid + 1;
            } else {
                return mid;
            }
        }

        return n;
    }
};
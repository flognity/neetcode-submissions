class Solution {
    std::vector<int> memo{1, 1}; // ways for n = 0 and n = 1
public:
    int climbStairs(int n) {
        // Challenge: Solve this recursively (less efficient).
        // Problem: exceeds time limit.

        // Safeguard for invalid input
        if (n < 0) {
            return 0;
        }

        // Ensure memo has an entry for index n
        if (memo.size() <= n) {
            memo.resize(n + 1, 0);
        }

        // Base cases
        if (n <= 1) {
            return 1;
        }

        // Return the cached result if available
        if (memo[n] != 0)
            return memo[n];

        // either climb 2 stairs, or 1 stair at at time
        memo[n] = climbStairs(n - 1) + climbStairs(n - 2);

        return memo[n];
    }
};

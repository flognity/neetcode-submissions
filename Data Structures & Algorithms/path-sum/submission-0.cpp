/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) {
            return false;
        }

        // helper to recursively get the path sum
        auto fnGetPathSum = [&targetSum](auto &self, TreeNode* node, vector<int> &sum) -> bool {
            if(!node) {
                return false;
            }

            sum.push_back(node->val);
            
            // only one path is needed, so exit out if we reach the end
            if(!node->left && !node->right) {
                bool matched = std::accumulate(sum.begin(), sum.end(), 0) == targetSum;
                sum.pop_back();
                return matched;
            }
            if(self(self, node->left, sum))
                return true;
            if(self(self, node->right, sum))
                return true;

            sum.pop_back();
            return false;
        };

        vector<int> sum = {};
        return fnGetPathSum(fnGetPathSum, root, sum);
    }
};
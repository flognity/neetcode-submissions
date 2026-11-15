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
    bool isBalanced(TreeNode* root) {
        if(root == nullptr)
            return true;

        // to check for balanced, we need to go all the way down to the 
        // leaf and check upwards from there

        int isB = isBalanced(root->left);
        if(!isB)
            return false;

        int left  = getHight(root->left);
        int right = getHight(root->right);
        
        isB = std::abs(right - left) < 2;

        if(!isB)
            return false;

        isB = isBalanced(root->right);

        return isB;
    }

    int getHight(TreeNode* root) {
        if(root == nullptr)
            return 0;

        return 1 + std::max(getHight(root->left), getHight(root->right));
    }
};

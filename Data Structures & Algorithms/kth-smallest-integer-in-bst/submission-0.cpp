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
    int kthSmallest(TreeNode* root, int k) {
        if (root == nullptr)
            return 0;
        // we need to raverse in order from smalles to largest
        // and stop at the k-th element
        int counter = 0;
        return findSmallest(root, counter, k);
    }

    int findSmallest(TreeNode* root, int &counter, int target) {
        if (root == nullptr)
            return -1;

        int leftResult = findSmallest(root->left, counter, target);
        if (leftResult != -1)
            return leftResult;

        // if we reach this point, we have explored the left side
        ++counter;
        if(counter == target)
            return root->val;

        // now explore the right side
        return findSmallest(root->right, counter, target);
    }
};

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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == nullptr)
            return {};

        vector<int> out = {};
        // go all the way to the left most point
        vector<int> left = inorderTraversal(root->left);

        // add all left points to our output
        for(int &i: left)
            out.push_back(i);

        // add the current node to out output
        out.push_back(root->val);

        // go all the way to the right most point
        vector<int> right = inorderTraversal(root->right);

        // add all the right points
        for(int &i: right)
            out.push_back(i);

        return out;
    }
};
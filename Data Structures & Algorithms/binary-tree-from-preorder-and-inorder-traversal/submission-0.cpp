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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size() != inorder.size() || preorder.size() < 1 || inorder.size() < 1)
            return nullptr;

        // the root element of the tree node will be the first element of preorder
        TreeNode *root = new TreeNode(preorder[0]);

        if(preorder.size() == 1)
            return root;

        // now we need to figure out based on preorder, 
        // whether to go left or right from here
        TreeNode *curr = root;

        // find the root's key in the inorder vector
        auto it = std::find(inorder.begin(), inorder.end(), root->val);
        // calculate the index from the iterator
        int mid = it - inorder.begin();

        // construct sub-arrays:
        // everything to the left of mid (including mid) in preorder goes to the left
        vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + mid + 1);
        vector<int> leftInorder(inorder.begin(), inorder.begin() + mid);
        root->left = buildTree(leftPreorder, leftInorder);

        // everything to the right of mid in preorder goes to the right
        vector<int> rightPreorder(preorder.begin() + mid + 1, preorder.end());
        vector<int> rightInorder(inorder.begin() + mid + 1, inorder.end());
        root->right = buildTree(rightPreorder, rightInorder);

        return root;
    }
};

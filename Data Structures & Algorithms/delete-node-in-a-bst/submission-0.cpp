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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr)
            return root;

        if(key < root->val) {
            // search further down the left
            root->left = deleteNode(root->left, key);
        } else if (key > root->val) {
            // search further down the right
            root->right = deleteNode(root->right, key);
        } else {
            // delete this node
            // 2 cases: - root has 0 or 1 children
            //          - root has 2 children
            if(root->right == nullptr) {
                return root->left;
            } else if (root->left == nullptr) {
                return root->right;
            } else {
                // root has 2 children

                // we need to find the minimum to the right of root
                TreeNode* minNode = findMinimum(root->right);

                // Before we hook up the new node, delete it's old position
                minNode->right = deleteNode(root->right, minNode->val);

                // The minNode will become the new current node
                // Link the new nodes left to the old tree's left
                minNode->left = root->left;
                root = minNode;
            }
        }

        return root;
    }
    
    TreeNode* findMinimum(TreeNode* root) {
        if(root != nullptr && root->left != nullptr)
            return findMinimum(root->left);

        return root;
    }

};
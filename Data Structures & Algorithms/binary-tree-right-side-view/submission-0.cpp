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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> out = {};
        if(root == nullptr)
            return out;

        std:queue<TreeNode *> q = {};
        q.push(root);
        while(q.size() > 0) {
            // we have a queue with all of this level's nodes;
            // the back of the queue will contain the most right node
            out.push_back(q.back()->val);

            int levelSize = q.size();
            for(size_t i = 0; i < levelSize; ++i) {
                // pop the previous' level's nodes
                TreeNode *node = q.front();
                q.pop();

                // add this level's nodes 
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }
        }

        return out;
    }
};

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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> out = {};
        if(root == nullptr)
            return out;

        // add each level's nodes to the queue and then empty the 
        // queue into the level vector
        std::queue<TreeNode *> q;
        q.push(root);
        while(q.size() > 0) {
            vector<int> level = {};
            // loop over the current q size, which represents one level
            int thisLevelSize = (int)q.size();
            for(int i = 0; i < thisLevelSize; ++i) {
                // add the value to the level
                TreeNode *node = q.front();
                level.push_back(node->val);
                q.pop();
                
                // queue up the nodes for the next level
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
            }

            // add the level to the output
            out.push_back(level);
        }

        return out;
    }
};

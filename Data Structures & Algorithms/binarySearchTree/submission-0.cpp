class TreeMap {
private:
    struct TreeNode {
        int key;
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode(int _key, int _val) : key(_key), val(_val), left(nullptr), right(nullptr) {};
    };
    TreeNode *root;

    TreeNode* removeNode(TreeNode* node, int key) {
        if (!node) 
            return nullptr;
            
        if (key < node->key) {
            node->left = removeNode(node->left, key);
        } else if (key > node->key) {
            node->right = removeNode(node->right, key);
        } else {
            if (!node->left) {
                TreeNode* rightChild = node->right;
                delete node;
                return rightChild;
            } else if (!node->right) {
                TreeNode* leftChild = node->left;
                delete node;
                return leftChild;
            } else {
                TreeNode* minNode = node->right;
                while (minNode->left) {
                    minNode = minNode->left;
                }
                node->key = minNode->key;
                node->val = minNode->val;
                node->right = removeNode(node->right, minNode->key);
            }
        }
        return node;
    }

public:
    TreeMap() {
        root = nullptr;
    }
    ~TreeMap() {
        // delete all TreeNode pointers
        // queue all elements up and delete them
        if (!root) return;
        std::queue<TreeNode*> q;
        q.push(root);
        while(q.size() > 0) {
            int levelSize = q.size();
            for(size_t i = 0; i < levelSize; ++i) {
                TreeNode *node = q.front();
                q.pop();
                if(node->left)
                    q.push(node->left);
                if(node->right)
                    q.push(node->right);
                
                // delete the node
                delete node;
            }
        }
    }

    void insert(int key, int val) {
        if(!root) {
            root = new TreeNode(key, val);
            return;
        }

        // start at root
        TreeNode* node = root;
        // perform insert in BST
        while (node) {
            if(key < node->key) {
                if (!node->left) {
                    node->left = new TreeNode(key, val);
                    return;
                }
                node = node->left;
            } else if (key > node->key) {
                if (!node->right) {
                    node->right = new TreeNode(key, val);
                    return;
                }
                node = node->right;
            } else {
                node->val = val;
                return;
            }
        }
    }

    int get(int key) {        
        // start at root
        TreeNode* node = root;
        // perform search in BST
        while (node) {
            if(key < node->key) {
                node = node->left;
            } else if (key > node->key) {
                node = node->right;
            } else {
                return node->val;
            }
        }

        return -1;
    }

    int getMin() {
        // start at root
        TreeNode* node = root;
        // min is the leaf on the far left
        while (node) {
            if(node->left)
                node = node->left;
            else
                return node->val;
        }

        return -1;
    }

    int getMax() {
        // start at root
        TreeNode* node = root;
        // max is the leaf on the far right
        while (node) {
            if(node->right)
                node = node->right;
            else
                return node->val;
        }

        return -1;

    }

    void remove(int key) {
        root = removeNode(root, key);
    }

    std::vector<int> getInorderKeys() {
        std::vector<int> out = {};
        
        TreeNode *node = root;
        std::stack<TreeNode*> s = {};
        // go all the way to the left first
        while(node || !s.empty()) {
            if(node) {
                s.push(node);
                node = node->left;
            } else {
                node = s.top();
                s.pop();
                out.push_back(node->key);
                node = node->right;
            }
        }

        return out;
    }
};

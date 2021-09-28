
class Solution {
public:
    int goodNodes(TreeNode* root) {
        int res = 0;
        int currentMax = INT_MIN;
        if(root == nullptr)
            return 0;
        
        if(root->val >= currentMax) {
            currentMax = root->val;
            res++;
        }
        goodNodesFind(root->left, currentMax, res);
        goodNodesFind(root->right, currentMax, res);
        return res; 
    }
    
    void goodNodesFind(TreeNode* root, int currentMax, int& res) {
        if(root == nullptr)
            return;
        
        if(root->val >= currentMax) {
            currentMax = root->val;
            res++;
        }
        goodNodesFind(root->left, currentMax, res);
        goodNodesFind(root->right, currentMax, res);
    }
};

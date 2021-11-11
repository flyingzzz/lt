class Solution {
    
public:
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0;
        helperSum(root, low, high, ans);
        return ans;
    }
    void helperSum(TreeNode* root, int low, int high, int& ans) {
        if(root == NULL) return;
        if(root->val >= low && root->val <= high)
            ans += root->val;
        helperSum(root->left, low, high, ans);
        helperSum(root->right, low, high, ans);
    }
};

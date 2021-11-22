class Solution {
public:
    int distributeCoins(TreeNode* root) {
        int res = 0;
        balance(root, res);
        return res;
    }
    int balance(TreeNode* root, int &res) {
        if(root == NULL) return 0;
        int left = balance(root->left, res);
        int right = balance(root->right, res);
        res += abs(left) + abs(right);
        return root->val - 1 + left + right;
    }
};

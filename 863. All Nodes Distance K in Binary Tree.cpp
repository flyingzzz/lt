class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        //初始化，dfs调用，返回值
        if(!root) return {};
        vector<int> res;
        unordered_map<TreeNode*, vector<TreeNode*>> map;
        unordered_set<TreeNode*> visited{{target}};
        queue<TreeNode*> que{{target}};
        dfs(root, NULL, map);
        
        while(!que.empty()) {
            if(k == 0) {
                for(int i = que.size(); i > 0; --i) {
                    res.push_back(que.front()->val);
                    que.pop();
                }
                return res;
            } else {
                for(int i = que.size(); i > 0; --i) {
                    TreeNode* tmp = que.front(); que.pop();
                    for(TreeNode* node : map[tmp]) {
                        if(visited.count(node)) continue;
                        que.push(node);
                        visited.insert(node);
                    }
                }
                --k;
            }
        }
        
        return {};
    }
    
    void dfs(TreeNode* node, TreeNode* pre, unordered_map<TreeNode*, vector<TreeNode*>>& map) {
        if(!node) return;
        if(map.count(node)) return;
        if(pre) {
            map[node].push_back(pre);
            map[pre].push_back(node);
        }
        
        dfs(node->left, node, map);
        dfs(node->right, node, map);
    }
};

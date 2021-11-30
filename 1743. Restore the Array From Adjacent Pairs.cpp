class Solution {
public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs) {
        unordered_map<int, vector<int>> umap;
        for(auto & adjacent : adjacentPairs) {
            umap[adjacent[0]].push_back(adjacent[1]);
            umap[adjacent[1]].push_back(adjacent[0]);
        }
        
        vector<int> res;
        for(auto & node : umap) {
            if(node.second.size() == 1) {
                res.push_back(node.first);
                res.push_back(node.second[0]);
                break;
            }
        }
        while(res.size() < adjacentPairs.size() + 1) {
            int tail = res.back(), pre = res[res.size() - 2];
            if(umap[tail][0] != pre) {
                res.push_back(umap[tail][0]);
            } else {
                res.push_back(umap[tail][1]);
            }
        }
        return res;
    }
};

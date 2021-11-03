class SparseVector {
public:
    unordered_map<int, int> umap;
public:
    
    SparseVector(vector<int> &nums) {
        for(int i = 0; i < nums.size(); ++i) {
            if(nums[i] != 0) {
                umap[i] = nums[i];
            }
        }
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int res = 0;
        for(auto pair : umap) {
            if(vec.umap[pair.first] != 0) {
                res += pair.second * vec.umap[pair.first];
            }
        }
        return res;
    }
};

class Solution {
private:
    vector<int> prefixSum;
public:
    Solution(vector<int>& w) {
        prefixSum = w;
        for(int i = 1; i < w.size(); i++) {
            prefixSum[i] = prefixSum[i - 1] + w[i];
        }
    }
    
    int pickIndex() {
        int r = rand() % prefixSum.back();
        int left = 0; 
        int right = prefixSum.size() - 1;
        while(left < right) {
            int mid = left + (right - left)/2;
            if(prefixSum[mid] <= r)
                left = mid + 1;
            else
                right = mid;
        }
        
        return right;
    }
};

class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxDegree = 0;
        int len = n;
        unordered_map<int, int> left;
        unordered_map<int, int> right;
        unordered_map<int, int> count;
        
        for(int i = 0; i < n; ++i) {
            if(left.count(nums[i]) == 0) {
                left[nums[i]] = i;
            } else {
                right[nums[i]] = i;
            }
            count[nums[i]] += 1;
            maxDegree = max(maxDegree, count[nums[i]]);
        }
        
        if(maxDegree == 1) return 1;
        for(auto element : count) {
            if(element.second == maxDegree) {
                int tmp = right[element.first] - left[element.first] + 1;
                len = min(len, tmp);
            }
        }
        return len;
    }
};

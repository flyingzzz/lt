class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int res = 0, sum = 0;
        vector<int> cnt(k, 0);
        cnt[0] = 1;
        for(int i = 0; i < nums.size(); ++i) {
            sum = (sum + nums[i] % k + k ) % k;
            res += cnt[sum];
            cnt[sum]++;
        }
        return res;
        /*int res = 0;
        vector<int> presum(nums);
        int n = nums.size();
        for(int i = 1; i < n; ++i) {
            presum[i] = presum[i - 1] + nums[i];
        }
        
        for(int i = 0; i < n; ++i) {
            if(presum[i] % k == 0) {
                ++res;
            }
            for(int j = i + 1; j < n; ++ j)
                if((presum[j] - presum[i]) % k == 0) {
                    res++;
                }
        }
        return res;*/
    }
};

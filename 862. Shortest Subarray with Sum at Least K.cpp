class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {  
        int n = nums.size(), res = INT_MAX;
        deque<int> dq;
        vector<int> sums(n + 1, 0);
        for (int i = 1; i <= n; ++i) sums[i] = sums[i - 1] + nums[i - 1];
        
        for(int i = 0; i <= n; ++i) {
            while (!dq.empty() && sums[i] - sums[dq.front()] >= k) {
                res = min(res, i - dq.front());
                dq.pop_front();
            }     
            while(!dq.empty() && sums[i] <= sums[dq.back()]) {
                dq.pop_back();
            }
            dq.push_back(i);
        }
        return res == INT_MAX ? -1 : res;
    }
};

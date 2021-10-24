class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        //2,2,3,3,3,4
        //dp
        //0 0 2 3 1 0
        //using 0 0 4 9 8
        //avoid 0 0 0 4 9
        //pre   -1 0 2 3
        int n = nums.size();
        if(nums.size() == 1) return nums[0];
        vector<int> count(10001, 0);
        for(int num : nums) {
            count[num]++;
        }
        int use = 0, avoid = 0, pre = -1;
        for(int k = 0; k < 10001; ++k) {
            if(count[k] > 0) {
                int m = max(use, avoid);
                if(k - 1 != pre) {
                    use = k*count[k] + m;
                    avoid = m;
                } else {
                    use = k*count[k] + avoid;
                    avoid = m;
                }
                pre = k;
            }
        }
        
        return max(use, avoid);
    }
};

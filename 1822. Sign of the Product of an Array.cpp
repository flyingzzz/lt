class Solution {
public:
    int arraySign(vector<int>& nums) {
        int res;
        int countNegative;
        for(auto num : nums) {
            if(num == 0) {
                return 0;
            } else if(num < 0) {
                ++countNegative;
            }
        }
        
        if(countNegative % 2 == 0) {
            return 1;
        } else {
            return -1;
        }
    }
};

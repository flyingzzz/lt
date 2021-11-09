class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int left = -1;
        int right = 0;
        for(auto &weight : weights) {
            left = max(left, weight);
            right += weight;
        }
        while(left < right) {
            int cur = 0;
            int need = 0;
            int mid = (right - left)/2 + left;
            for(int i = 0; i < weights.size(); ++i) {
                if(cur + weights[i] > mid) {
                    cur = weights[i];
                    need++;
                } else if(cur + weights[i] == mid) {
                    cur = 0;
                    need++;
                } else {
                    cur += weights[i];
                }
                if(need > days)// cannot be >= here
                    break;
            }
            if(cur > 0) need++;//for array end case,must notice!!!
            if(need > days) {
                left = mid + 1;
            } else {
                right = mid;
            }
        }
        return left;
    }
};

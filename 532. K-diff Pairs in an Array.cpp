class Solution {
public:
    //another way to use sort and two pointer, becare of case 0
    int findPairs(vector<int>& nums, int k) {
        int result = 0;
        unordered_map<int, int> counter;
        for(auto &num : nums) {
            counter[num]++;
        }
        for(auto &[key, value] : counter) {
            if(k > 0 && counter.find(key + k) != counter.end()) {
                result++;
            } else if(k == 0 && value > 1) {
                result++;
            }
        }
        return result;
    }
};

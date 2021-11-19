class Solution {
public:
    int minDeletions(string s) {
        vector<int> nums(26, 0);
        unordered_set<int> singles;
        int res = 0;
        for(auto c : s) {
            nums[c - 'a']++;
        }
        
        for(int i = 0; i < 26; ++i) {
            while(nums[i] > 0 && singles.find(nums[i]) != singles.end()) {
                res++;
                nums[i]--;
            }
            if(nums[i] > 0) {
                singles.insert(nums[i]);
            }
        }
        return res;
    }
};

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int, int> nums;
        for(auto num : arr) {
            nums[num]++;
        }
        priority_queue<int, vector<int>, greater<int>> counts;
        for(auto &[num, count] : nums) {
            counts.push(count);
        }
        while(counts.size() > 0 & k > 0) {
            if(counts.top() > k) {
                return counts.size();
            } else if(counts.top() == k) {
                return counts.size() - 1;
            } else {
                k -= counts.top();
                counts.pop();
            }
        }
        return counts.size();
    }
};

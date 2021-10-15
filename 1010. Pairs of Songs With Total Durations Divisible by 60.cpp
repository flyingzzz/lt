class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        //count must be initialized
        int count = 0;
        vector<int> remainders(60, 0);
        for(int t : time) {
            if(t % 60 == 0) {
                count += remainders[0];
            } else {
                count += remainders[60 - t%60];
            }
            
            ++remainders[t % 60];
        }
        return count;
    }
};

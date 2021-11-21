class Solution {
public:
    int knightDialer(int n) {
        int res = 0; 
        int mod = 1e9 + 7;
        vector<vector<int>> path{{4, 6}, {6, 8}, {7, 9}, {4,8}, {3, 9, 0}, 
                                 {}, {1, 7, 0}, {2, 6}, {1, 3}, {2, 4}};
        vector<vector<int>> dp(n, vector<int>(10));
        for(int i = 0; i < 10; i++) {
            dp[0][i] = 1;
        }
        for(int i = 1; i < n; ++i) {
            for(int j = 0; j < 10; j++) {
                for(auto num : path[j]) {
                    dp[i][j] = (dp[i][j] + dp[i - 1][num])%mod;
                }
            }
        }
        for(int i = 0; i < 10; i++) {
            res = (res + dp.back()[i])%mod;
        }
        return res;
    }
};

class Solution {
public:
    int consecutiveNumbersSum(int n) {
        //x, x+1, x+2, ..., x+k-1
        //kx + (k-1)k / 2 = N
        //kx = N - (k-1)k / 2
        //N - (k-1)k / 2 > 0
        //k < sqrt(2N)
        
        int res = 1;
        for (int i = 2; i < sqrt(2 * n); ++i) {
            if ((n - i * (i - 1) / 2) % i == 0) ++res;
        }
        return res;
    }
};

class Solution {
private:
    priority_queue<int> factors;
public:
    int kthFactor(int n, int k) {
        int x = sqrt(n);
        for(int i = 1 ; i < x + 1; ++i) {
            if(n % i == 0) {
                pushFactor(i, k);
                if( n / i != i) {
                    pushFactor(n/i, k);
                }
            }
        }
        return factors.size() >= k ? factors.top() : -1;
    }
    void pushFactor(int factor, int k) {
        factors.push(factor);
        if(factors.size() > k) {
            factors.pop();
        }
    }
};

class CustomStack {
private:
    vector<int> stack, inc;
    int maxCount;
public:
    CustomStack(int maxSize) {
        maxCount = maxSize;
    }
    
    void push(int x) {
        int n = stack.size();
        if(n >= maxCount) {
            return;
        }     
        stack.push_back(x);
        inc.push_back(0);
    }
    
    int pop() {
        int res = 0;
        if(stack.size() < 1) return -1;
        int i = stack.size() - 1;
        if(i > 0) {
            inc[i - 1] += inc[i];
        }
        res = stack[i] + inc[i];
        stack.pop_back();
        inc.pop_back();
        return res;
    }
    
    void increment(int k, int val) {
        int i = 0;
        int n = stack.size();
        //becare oversize here
        if(k > n) {
            i = n - 1;
        } else {
            i = k - 1;
        }
        if(i >= 0) {
            inc[i] += val;
        }
    }
};

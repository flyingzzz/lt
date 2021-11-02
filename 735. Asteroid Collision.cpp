class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stack;
        int noPush = 0;
        for(int ast : asteroids) {
            noPush = 0;
            while(!stack.empty() && ast < 0 && stack.top() > 0) {
                if(stack.top() < -ast) {
                    stack.pop();
                } else if(stack.top() == -ast) {
                    stack.pop();
                    noPush = 1;
                    break;
                } else {
                    noPush = 1;
                    break;
                }
            }
            if(noPush == 0) {
                stack.push(ast);
            }
        }
        
        int n = stack.size();
        vector<int> ans(n);
        for(int t = n - 1; t >=0; --t) {
            ans[t] = stack.top();
            stack.pop();
        }
        
        return ans;
    }
};

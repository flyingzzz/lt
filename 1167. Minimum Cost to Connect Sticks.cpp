class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        //Min priority queue
        //priority_queue<int, vector<int>, greater<int>> pq;
        int ans = 0;
        if(sticks.size() <= 1) return 0;
        priority_queue<int> pq;
        for(auto stick : sticks) {
            pq.push(-stick);
        }  
        while(pq.size() >= 2) {
            int num1 = pq.top();
            pq.pop();
            int num2 = pq.top();
            pq.pop();
            int sum = num1 + num2;
            ans += sum;
            pq.push(sum);
        }
        return -ans;
    }
};

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> ans(n, 0);
        stack<int> stack;
        for(int currDay = 0; currDay < n; ++currDay) {
            int currTemp = temperatures[currDay];
            while(!stack.empty() && temperatures[stack.top()] < currTemp) {
                int preDay = stack.top();
                stack.pop();
                ans[preDay] = currDay - preDay;
            }
            stack.push(currDay);
        }
        return ans;
    }
    /*
     public int[] dailyTemperatures(int[] temperatures) {
        int n = temperatures.length;
        int hottest = 0;
        int answer[] = new int[n];
        
        for (int currDay = n - 1; currDay >= 0; currDay--) {
            int currentTemp = temperatures[currDay];
            if (currentTemp >= hottest) {
                hottest = currentTemp;
                continue;
            }
            
            int days = 1;
            while (temperatures[currDay + days] <= currentTemp) {
                // Use information from answer to search for the next warmer day
                days += answer[currDay + days];
            }
            answer[currDay] = days;
        }
        
        return answer;
    }
    */
};

class Solution {
public:
    //http://zxi.mytechroad.com/blog/geometry/leetcode-759-employee-free-time/
    vector<Interval> employeeFreeTime(vector<vector<Interval>> schedule) {
        vector<Interval> all;
        for(auto &intervals: schedule) {
            all.insert(all.end(), intervals.begin(), intervals.end());
        }
        sort(all.begin(), all.end(), [](Interval &a, Interval &b){return a.start < b.start;});
        vector<Interval> ans;
        int end = all[0].end;
        for(auto &interval : all) {
            if(interval.start > end) {
                //ans.push_back(Interval(end, interval.start));
                ans.emplace_back(end, interval.start);
                end = interval.end;
            } else {
                end = max(end, interval.end);
            }
        }
        return ans;
    }
};

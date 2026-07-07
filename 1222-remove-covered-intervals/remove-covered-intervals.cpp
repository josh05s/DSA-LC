class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        
        sort(intervals.begin(), intervals.end(), [](const vector<int>& x, const vector<int>& y) {
            if (x[0] != y[0]) return x[0] < y[0];
            return x[1] > y[1];
        });

        int count = 0;
        int maxEnd = 0;

        for (int i = 0; i < intervals.size(); i++) {
            if (intervals[i][1] > maxEnd) {
                count += 1;
                maxEnd = intervals[i][1];
            }
        }

        return count;
    }
};

class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int s = intervals.size();
        vector<int> res;

        for (int i = 0; i < s; i++) {
            pair<int,int> best = {INT_MAX, -1};
            for (int j = 0; j < s; j++) {
                if ((intervals[j][0] >= intervals[i][1]) && (intervals[j][0] < best.first))  {
                    best = {intervals[j][0], j};
                }
            }
            res.push_back(best.second);
        }
        return res;
    }
};
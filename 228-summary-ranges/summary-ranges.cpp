class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> result;
        int size = nums.size();

        for (int i = 0; i < size; i++) {
            int start = nums[i];

            // extend while the next number is consecutive
            // (long long avoids overflow when nums[i] == INT_MAX)
            while (i + 1 < size && (long long)nums[i + 1] == (long long)nums[i] + 1) {
                i++;
            }

            if (start == nums[i]) {
                result.push_back(to_string(start));
            } else {
                result.push_back(to_string(start) + "->" + to_string(nums[i]));
            }
        }
        return result;
    }
};
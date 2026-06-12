class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int s = nums.size();
        bool firstFound = false;
        int a = -1;
        int b = -1;
        vector<int> res(2);

        for (int i = 0; i < s; i++) {
            if (nums[i] == target) {
                if (firstFound == true) {
                    b = i;
                }
                else {
                    firstFound = true;
                    a = i;
                    b = i;
                }
            }
        }
        res[0] = a;
        res[1] = b;

        return res;
    }
};
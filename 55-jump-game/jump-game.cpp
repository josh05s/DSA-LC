class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxJ = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (maxJ < 0) {
                return false;
            }
            if (nums[i] > maxJ) {
                maxJ = nums[i];
            }
            maxJ--;
        }

        return true;
    }
};
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int output = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (output < 2 || nums[i] != nums[output - 2]) {
                nums[output] = nums[i];
                output++;
            }
        }
        return output;
    }
};
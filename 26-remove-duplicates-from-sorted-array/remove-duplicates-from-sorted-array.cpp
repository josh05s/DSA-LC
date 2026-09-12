class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int output = 1;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != nums[output - 1]) {
                nums[output] = nums[i];
                output++;
            }
        }

        return output;
    }
};
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int majority = nums[0];

        for (int i = 0; i < nums.size(); i++) {
            if (count == 0) majority = nums[i];

            if (majority == nums[i]) count++;
            else count--;
        }

        return majority;
    }
};
class Solution {
public: // 0(1) approach for the second attempt, no notes or recitation
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j = m + n - 1;
        int k = m - 1;
        int l = n - 1;

        while (l >= 0) {
            if (k >= 0 && nums1[k] > nums2[l]) {
                nums1[j] = nums1[k];
                k--;
            }
            else  {
                nums1[j] = nums2[l];
                l--;
            }
            j--;
        }
    }
};
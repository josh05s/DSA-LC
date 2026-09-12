class Solution {
public: // 0(1) approach for the second attempt, no notes or recitation
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int j = m + n - 1; 
        int k = n - 1;
        int l = m - 1;

        while (k >= 0) {
            if (l >= 0 && (nums1[l] >= nums2[k])) {
                nums1[j] = nums1[l];
                l--;
            } else {
                nums1[j] = nums2[k];
                k--; 
            }
            j--;
        }
    }
};
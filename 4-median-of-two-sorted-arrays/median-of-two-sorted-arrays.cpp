class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        vector<int> numsTotal(n + m, 0);

        for (int i = 0; i < n; i++) {
            numsTotal[i] = nums1[i];
        }

        for (int i = 0; i < m; i++) {
            numsTotal[i + n] = nums2[i];
        }

        sort(numsTotal.begin(), numsTotal.end());

        int size = numsTotal.size();
        if (size % 2 == 0) {
            return (numsTotal[size/2] + numsTotal[(size/2) - 1])/2.0;
        }

        return numsTotal[size/2];
    }
};
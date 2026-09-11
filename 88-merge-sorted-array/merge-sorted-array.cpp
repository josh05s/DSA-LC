class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    vector<int> result(n + m);
    int mcount = 0;
    int ncount = 0;

    for (int i = 0; i < m + n; i++) {
        if (mcount < m && (ncount >= n || nums1[mcount] <= nums2[ncount])) {
            result[i] = nums1[mcount]; mcount++;
        } else {
            result[i] = nums2[ncount]; ncount++;
        }
    }

    nums1 = result; // copy merged result back into nums1
}
};
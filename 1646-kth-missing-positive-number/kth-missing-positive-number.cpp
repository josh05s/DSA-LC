class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int num = 1;
        int index = 0;

        while (k > 0) {
            if (index < arr.size() && arr[index] == num) {
                index++;
            }
            else {
                k--;
                if (k == 0) {
                    return num;
                }
            }
            num++;
        }

        return -1;
    }
};
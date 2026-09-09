class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        for (int location = 0; location <= 1000; location++) {
            int total = 0;
            
            for (int i = 0; i < trips.size(); i++) {
                int numPassengers = trips[i][0];
                int from = trips[i][1];
                int to = trips[i][2];
                
                if (from <= location && location < to) {
                    total += numPassengers;
                }
            }
            
            if (total > capacity) {
                return false;
            }
        }
        
        return true;
    }
};
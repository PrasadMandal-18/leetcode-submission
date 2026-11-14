
class Solution {
public:
    int findDay(vector<int>& weights, int cap) {
        int day = 1, load = 0;

        for(int i = 0; i < weights.size(); i++) {
            if(weights[i] + load > cap) {
                day++;
                load = weights[i];
            }
            else {
                load += weights[i];
            }
        }
        return day;
    }

    int shipWithinDays(vector<int>& weights, int days) {
        int maxi = INT_MIN;
        int sumation = 0;

        for(int i = 0; i < weights.size(); i++) {
            maxi = max(maxi, weights[i]);
            sumation += weights[i];
        }

        int low = maxi;
        int high = sumation;

        while(low <= high) {
            int mid = low + (high - low) / 2;

            int noofdays = findDay(weights, mid);

            if(noofdays <= days) {
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return low;
    }
};

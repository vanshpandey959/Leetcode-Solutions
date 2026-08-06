class Solution {
public:
    int countDays(vector<int>& weights, int weight) {
        int days = 1;
        int wt = 0;
        for(int i=0;i<weights.size();i++) {
            if(wt + weights[i] <= weight) {
                wt += weights[i];
            } else {
                days++;
                wt = weights[i];
            }
        }
        return days;
    }
    
    int shipWithinDays(vector<int>& weights, int days) {
        int maxi = INT_MIN, sum = 0;
        for(int i=0;i<weights.size();i++){
            sum += weights[i];
            maxi = max(maxi,weights[i]);
        }
        int low = maxi, high = sum, ans = -1;

        while(low <= high) {
            int mid = low + (high-low)/2;
            int dayss = countDays(weights, mid);
            if(dayss <= days) {
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }

        return ans;
    }
};
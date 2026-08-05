class Solution {
public:
    long long totalHours(vector<int>& piles, int banana) {
        long long totalhrs = 0;
        for(int i=0;i<piles.size();i++) {
            int hrs = ceil((double)piles[i] / banana);
            totalhrs += hrs;
        }
        return totalhrs;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int maxi = *max_element(piles.begin(), piles.end());
        int low = 1, high = maxi;
        int ans = INT_MAX;

        while(low <= high) {
            int mid = low + (high-low)/2;
            long long totalhrs = totalHours(piles, mid);
            if(totalhrs <= h) {
                ans = mid;
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return ans;
    }
};
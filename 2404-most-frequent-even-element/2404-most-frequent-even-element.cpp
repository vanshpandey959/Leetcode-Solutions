class Solution {
public:
    int mostFrequentEven(vector<int>& nums) {
        unordered_map<int, int> mpp;

        for (int i : nums) {
            if (i % 2 == 0) {
                mpp[i]++;
            }
        }

        int maxi = 0;
        int ans = -1;

        for (auto i : mpp) {
            if (i.second > maxi || 
                (i.second == maxi && i.first < ans)) {
                ans = i.first;
                maxi = i.second;
            }
        }

        return ans;
    }
};
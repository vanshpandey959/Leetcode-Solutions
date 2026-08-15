class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int maxIndex = 0; int minIndex = 0;

        for(int i=1;i<n;i++) {
            maxIndex = nums[i] > nums[maxIndex] ? i : maxIndex;
            minIndex = nums[i] < nums[minIndex] ? i : minIndex;
        }
        int small = 0, large = 0;
        if(minIndex < maxIndex) {
            small = minIndex;
            large = maxIndex;
        } else {
            large = minIndex;
            small = maxIndex;          
        }

        int maxRow1 = max(maxIndex, minIndex) + 1;
        int maxRow2 = n - min(maxIndex, minIndex);
        int maxBoth = small + (n-large+1);

        return min({maxRow1, maxRow2, maxBoth});
    }
};
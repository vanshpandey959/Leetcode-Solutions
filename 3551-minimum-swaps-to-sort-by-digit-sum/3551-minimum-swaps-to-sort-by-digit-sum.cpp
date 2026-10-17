class Solution {
public:
    int findDigitSum(int n) {
        int sum = 0;
        while(n) {
            int rem = n%10;
            sum += rem;
            n = n/10;
        }
        return sum;
    }
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        vector<int> a(nums);

        auto lambda = [&](int num1, int num2) {
            int digSum1 = findDigitSum(num1);
            int digSum2 = findDigitSum(num2);

            if(digSum1 != digSum2) {
                return digSum1 < digSum2;
            }
            return num1 < num2;
        };

        sort(a.begin(), a.end(), lambda);

        unordered_map<int, int> valToIndex;
        for(int i=0;i<n;i++) {
            valToIndex[nums[i]] = i;
        }
        
        int swap = 0;

        for(int i=0;i<n;i++) {
            int expectedVal = a[i];
            int currVal = nums[i];

            if(expectedVal == currVal) continue;

            int idx = valToIndex[expectedVal];
            nums[i] = expectedVal;
            nums[idx] = currVal;
            // Basically swap(nums[i], nums[idx]);

            valToIndex[expectedVal] = i;
            valToIndex[currVal] = idx;

            swap++;

        }
        return swap;
    }
};
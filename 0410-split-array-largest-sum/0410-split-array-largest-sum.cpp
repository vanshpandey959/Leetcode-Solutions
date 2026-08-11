class Solution {
public:
    int countArrays(vector<int>& arr, int sum) {
        int array = 1;
        int summ = 0;

        for(int i=0;i<arr.size();i++) {
            if(arr[i] + summ > sum){
                array++;
                summ = arr[i];
            } else {
                summ += arr[i];
            }
        }
        return array;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(),0);

        while(low <= high) {
            int mid = low + (high-low)/2;
            int array = countArrays(nums, mid);
            if(array > k) {
                low = mid+1;
            } else {
                high = mid-1;
            }
        }
        return low;
    }
};
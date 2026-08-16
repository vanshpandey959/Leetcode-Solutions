class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int i = -1;
        for(int j=0;j<n;j++) {
            if(nums[j] == 0) {
                i = j;
                break;
            }
        }
        if(i==-1) return;
        for(int j=i+1;j<n;j++) {
            if(nums[j] != 0) {
                swap(nums[j], nums[i]);
                i++;
            }
        }
    }
};
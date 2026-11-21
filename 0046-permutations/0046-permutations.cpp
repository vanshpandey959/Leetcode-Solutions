class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> temp;
        vector<int> frq(nums.size(), 0);
        help(nums,temp,frq,ans);
        return ans;
    }
    void help(vector<int>& nums,vector<int>& temp,vector<int>& frq, vector<vector<int>>& ans){
        if(temp.size() == nums.size()) {
            ans.push_back(temp);
            return;
        }

        for(int i=0;i<nums.size();i++) {
            if(!frq[i]) {
                temp.push_back(nums[i]);
                frq[i] = 1;
                help(nums,temp,frq,ans);

                frq[i] = 0;
                temp.pop_back();
            }
        }
    } 
};
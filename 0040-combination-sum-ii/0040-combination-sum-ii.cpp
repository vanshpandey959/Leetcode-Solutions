class Solution {
public:
    void help(int ind, int target,vector<vector<int>>& ans, vector<int>& temp,vector<int>& arr){
        if(target == 0) {
            ans.push_back(temp);
            return;
        }
        for(int i=ind; i<arr.size(); i++) {
            if(i>ind && arr[i]==arr[i-1]) continue;
            if(arr[i] > target) break;

            temp.push_back(arr[i]);
            help(i+1,target-arr[i],ans,temp,arr);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> temp;
        help(0,target,ans,temp,candidates);
        return ans;
    }
};
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans;
        long long num = 1;
        ans.push_back(num);
        int row = rowIndex+1;

        for(int i=1;i<row;i++) {
            num = num * (row-i);
            num = num / i;
            ans.push_back(num);
        }

        return ans;
    }
};
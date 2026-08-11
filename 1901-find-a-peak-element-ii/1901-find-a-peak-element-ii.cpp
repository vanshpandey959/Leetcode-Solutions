class Solution {
public:

    int findMax(vector<vector<int>>& mat, int mid){
        int ind = -1; int maxi = INT_MIN;
        for(int i=0;i<mat.size();i++){
            if(maxi < mat[i][mid]){
                maxi = mat[i][mid];
                ind = i;
            }
        }
        return ind;
    }

    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();

        int low = 0, high = m-1;

        while(low <= high) {
            int mid = low + (high-low)/2;
            int maxInd = findMax(mat, mid);
            
            int left = mid-1 >= 0 ? mat[maxInd][mid-1] : -1;
            int right = mid+1 < m ? mat[maxInd][mid+1] : -1;

            if(mat[maxInd][mid] > left && mat[maxInd][mid] > right) {
                return {maxInd, mid};
            } else if(mat[maxInd][mid] < left) {
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return {-1, -1};
    }
    
};
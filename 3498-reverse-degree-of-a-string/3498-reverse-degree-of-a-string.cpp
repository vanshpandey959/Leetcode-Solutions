class Solution {
public:
    int reverseDegree(string s) {
        int n = s.size();
        int prod = 0;

        for(int i=0;i<n;i++) {
            int revInd = 'z' - s[i] + 1;
            prod += revInd*(i+1);
        }

        return prod;
    }
};
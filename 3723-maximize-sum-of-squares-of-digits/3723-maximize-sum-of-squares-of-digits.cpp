class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(9*num < sum) return "";
        int nines = sum/9;
        int remain = sum%9;

        string result(nines, '9');

        if(remain > 0) {
            result.push_back(remain + '0');
        }

        result.append(num - result.length(), '0');
        return result;
    }
};
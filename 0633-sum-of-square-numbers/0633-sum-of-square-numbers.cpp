class Solution {
public:
    bool judgeSquareSum(int c) {
        long long i = 0;
        long long j = floor(sqrt(c));

        while (i <= j) {
            long long sq = i * i + j * j;

            if (sq == c) return true;
            else if (sq < c) i++;
            else j--;
        }

        return false;
    }
};
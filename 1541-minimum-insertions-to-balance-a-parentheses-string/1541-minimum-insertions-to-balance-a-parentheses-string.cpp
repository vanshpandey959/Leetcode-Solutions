class Solution {
public:
    int minInsertions(string s) {
        int n = s.size();
        int count = 0;
        int i = 0;
        int result = 0;
        
        while(i < n) {
            if(s[i] == '(') {
                count++;
                i++;
            } else {
                if(count > 0) {
                    count--;
                } else {
                    result += 1;
                }

                if(s[i+1] == ')') {
                    i+=2;
                } else {
                    result += 1;
                    i++;
                }
            }
        }

        return result + count*2;
    }
};
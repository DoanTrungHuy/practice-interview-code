class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        
        string sav[numRows];
        int step = 0;
        const int n = s.size();
        
        for (int i = 0, j = 0; i < n; ++i) {
            sav[j] += s[i];
            if (j == 0) {
                step = 1;
            }
            else if (j == numRows - 1) {
                step = -1;
            }
            j += step;
        }
        
        string ans = "";
        
        for (int i = 0; i < numRows; ++i) {
            ans += sav[i];
        }
        
        return ans;
    }
};
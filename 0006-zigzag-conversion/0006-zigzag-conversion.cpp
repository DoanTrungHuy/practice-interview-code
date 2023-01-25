class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) {
            return s;
        }
        vector<string> listStr(numRows);
        int n = (int)s.size();
        int step = 1;
        int k = 0;
        for (int i = 0; i < n; ++i) {
            listStr[k] += s[i];
            if (k == numRows - 1) {
                step = -1;
            }
            else if (k == 0) {
                step = 1;
            }
            k += step;
        }
        string res;
        for (string str : listStr) {
            res += str;
        }
        return res;
    }
};
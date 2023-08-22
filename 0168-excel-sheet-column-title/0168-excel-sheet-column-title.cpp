class Solution {
public:
    string convertToTitle(int columnNumber) {
        int n = columnNumber;
        string s;
        while (n > 0) {
            n--;
            int m = n % 26;
            n /= 26;
            s.push_back(m + 'A');
        }
        reverse(s.begin(), s.end());
        return s;
    }
};
class Solution {
public:
    bool isPalindrome(string s) {
        string t;
        
        for (char c : s) {
            c = tolower(c);
            if ('a' <= c and c <= 'z') {
                t += c;
            }
            else if ('0' <= c and c <= '9') {
                t += c;
            }
        }
        
        return t == string(t.rbegin(), t.rend());
    }
};
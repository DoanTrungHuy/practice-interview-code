class Solution {
public:
    int appendCharacters(string s, string t) {
        if (s.find(t) != string::npos) {
            return 0;
        }
        int j = 0;
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == t[j]) {
                j++;
            }
        }
        return t.size() - j;
    }
};
class Solution {
public:
    char findTheDifference(string s, string t) {
        vector<int> cnt1(26, 0), cnt2(26, 0);
        
        for (char c : s) {
            cnt1[c - 'a']++;
        }
        
        for (char c : t) {
            cnt2[c - 'a']++;
        }
        
        for (int c = 0; c < 26; ++c) {
            if (cnt2[c] - cnt1[c] > 0) {
                return c + 'a';
            }
        }
        
        return ' ';
    }
};
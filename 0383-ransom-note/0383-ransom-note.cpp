class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int cnt1[26] = {0}, cnt2[26] = {0};
        for (char c : ransomNote) {
            cnt1[c - 'a']++;
        }
        for (char c : magazine) {
            cnt2[c - 'a']++;
        }
        for (char c : ransomNote) {
            if (cnt1[c - 'a'] > cnt2[c - 'a']) {
                return false;
            }
        }
        return true;
    }
};
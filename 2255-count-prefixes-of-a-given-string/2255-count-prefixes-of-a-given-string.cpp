class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int cnt = 0;
        for (string word : words) {
            int i = 0;
            for (char c : word) {
                if (c == s[i]) {
                    i++;
                }
            }
            cnt += i == word.size();
        }
        return cnt;
    }
};
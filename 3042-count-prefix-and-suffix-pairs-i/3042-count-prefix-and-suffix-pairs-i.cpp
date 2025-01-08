class Solution {
public:
    bool is_valid(string s, string t) {
        if (t.size() > s.size()) {
            return false;
        }
        
        for (int i = 0; i < t.size(); ++i) {
            if (t[i] != s[i]) {
                return false;
            }
        }
        
        int i = s.size() - 1, j = t.size() - 1;
        
        while (j >= 0) {
            if (s[i] != s[j]) {
                return false;
            }
            i--;
            j--;
        }
        
        return true;
    }
    
    int countPrefixSuffixPairs(vector<string>& words) {
        const int n = words.size();
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                ans += is_valid(words[j], words[i]);
            }
        }
        
        return ans;
    }
};
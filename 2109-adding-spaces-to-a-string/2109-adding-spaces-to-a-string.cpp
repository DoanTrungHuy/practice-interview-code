class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string ans = "";
        int n = s.size(), j = 0;
        
        for (int i = 0; i < n; ++i) {
            if (j < spaces.size() and i == spaces[j]) {
                ans += " ";
                j += 1;
            }
            ans += s[i];
        }
        
        return ans;
    }
};
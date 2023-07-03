class Solution {
public:
    bool buddyStrings(string s, string goal) {
        int n = s.size();
        int m = goal.size();
        
        if (n != m) {
            return false;
        }
        
        int diff1 = -1, diff2 = -1;
        unordered_set<char> us;
        
        for (int i = 0; i < n; ++i) {
            if (s[i] != goal[i]) {
                if (diff1 == -1) {
                    diff1 = i;
                }
                else if (diff2 == -1) {
                    diff2 = i;
                }
                else {
                    return false;
                }
            }
            us.insert(s[i]);
        }
        
        if (diff1 != -1 and diff2 != -1) {
            return s[diff1] == goal[diff2] and s[diff2] == goal[diff1];
        }
        
        if (diff1 != -1) {
            return false;
        }
        
        return (int)(us.size()) < n;
    }
};
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int cnt = 0;
        
        // Time: O(26 * n) -> 1s
        // Space: O(26)
        
        for (char c = 'a'; c <= 'z'; ++c) {
            // string::npos -> 10^19
            unsigned int idx1 = s.find(c);
            unsigned int idx2 = s.rfind(c);
            
            if (idx1 == string::npos or (idx2 - idx1 + 1) < 3) {
                continue;
            }
            
            unordered_set<int> us(s.begin() + idx1 + 1, s.begin() + idx2);
            
            cnt += us.size();
        }
        
        return cnt;
    }
};
class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int cnt = 0;
        
        for (char c = 'a'; c <= 'z'; ++c) {
            unsigned long idx1 = s.find(c);
            unsigned long idx2 = s.rfind(c);
            
            if (idx1 == string::npos or (idx2 - idx1 + 1) < 3) {
                continue;
            }
            
            unordered_set<int> us(s.begin() + idx1 + 1, s.begin() + idx2);
            
            cnt += us.size();
        }
        
        return cnt;
    }
};
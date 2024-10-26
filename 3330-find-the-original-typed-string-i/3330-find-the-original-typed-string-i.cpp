class Solution {
public:
    int possibleStringCount(string word) {
        // 2TH
        // TH1: Alice gõ đúng, chuỗi là word ban đầu
        // Th2: Alice gõ sai 1 key nào đó nhiều lần
        
        const int n = word.size();
        int ans = 1;    // TH1
        
        for (int i = 0; i < n;) {
            int j = 1;
            
            while (i + j < n && word[i] == word[i + j]) {
                j++;
            }
            
            ans += j - 1;   // TH2
            i += j;
        }
        
        return ans;
    }
};
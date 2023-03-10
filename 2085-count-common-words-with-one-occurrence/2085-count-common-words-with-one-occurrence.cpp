class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> us1, us2;
        
        for (string word : words1) {
            us1[word]++;
        }
        
        for (string word : words2) {
            us2[word]++;
        }
        
        int cnt = 0;
        
        for (string word : words1) {
            if (us1[word] == 1 and us2.count(word) and us2[word] == 1) {
                cnt++;
            }
        }
        
        return cnt;
    }
};
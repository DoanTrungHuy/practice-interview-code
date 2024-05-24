class Solution {
private:
    vector<int> score;
    
public:
    int calc_score(vector<int> &cnt, string word) {
        int sum = 0;
        for (char c : word) {
            cnt[c - 'a']--;
            if (cnt[c - 'a'] < 0) {
                return INT_MIN;
            }
            sum += score[c - 'a'];
        }
        return sum;
    }
    
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        this->score = score;
        int n = words.size();
        vector<int> cnt(26, 0);
        
        for (char c : letters) {
            cnt[c - 'a']++;
        }
        
        int ans = INT_MIN;
        
        for (int mask = 1; mask < (1 << n); ++mask) {
            vector<int> dummy = cnt;
            int sum = 0;
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    int calc = calc_score(dummy, words[i]);
                    if (calc == INT_MIN) {
                        break;
                    }
                    sum += calc;
                }
            }
            ans = max(ans, sum);
        }
        
        return ans;
    }
};
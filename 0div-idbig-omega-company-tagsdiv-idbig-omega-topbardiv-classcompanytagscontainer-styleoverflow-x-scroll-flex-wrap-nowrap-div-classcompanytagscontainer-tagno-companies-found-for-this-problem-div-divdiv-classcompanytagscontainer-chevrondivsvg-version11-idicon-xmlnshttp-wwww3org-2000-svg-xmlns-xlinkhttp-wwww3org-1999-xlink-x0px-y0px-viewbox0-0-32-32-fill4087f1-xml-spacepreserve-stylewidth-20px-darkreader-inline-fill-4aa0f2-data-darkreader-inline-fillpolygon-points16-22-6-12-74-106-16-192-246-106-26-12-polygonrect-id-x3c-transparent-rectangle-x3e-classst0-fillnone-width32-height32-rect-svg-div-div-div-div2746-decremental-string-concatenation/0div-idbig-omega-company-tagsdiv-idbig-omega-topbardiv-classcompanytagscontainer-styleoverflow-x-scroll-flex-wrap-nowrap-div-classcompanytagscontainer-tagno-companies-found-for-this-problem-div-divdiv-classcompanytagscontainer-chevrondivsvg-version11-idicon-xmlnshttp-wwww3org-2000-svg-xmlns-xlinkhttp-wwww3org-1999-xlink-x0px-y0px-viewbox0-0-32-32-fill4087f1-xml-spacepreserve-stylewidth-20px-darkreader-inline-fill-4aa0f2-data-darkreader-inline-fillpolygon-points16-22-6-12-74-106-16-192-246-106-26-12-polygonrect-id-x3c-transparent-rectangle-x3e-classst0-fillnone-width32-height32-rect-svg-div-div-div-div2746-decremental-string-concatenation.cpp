int memo[1001][26][26];

class Solution {
private:
    vector<string> words;
    int n;
    
public:
    int dp(int i, char first, char last) {
        if (i == n) {
            return 0;
        }
        if (memo[i][first - 'a'][last - 'a'] != -1) {
            return memo[i][first - 'a'][last - 'a'];
        }
        return memo[i][first - 'a'][last - 'a'] = words[i].size() + min(
            -(last == words[i][0]) + dp(i + 1, first, words[i][words[i].size() - 1]),
            -(words[i][words[i].size() - 1] == first) + dp(i + 1, words[i][0], last)
        );
    }
    
    int minimizeConcatenatedLength(vector<string>& words) {
        memset(memo, -1, sizeof(memo));
        this->words = words;
        this->n = words.size();
        return words[0].size() + dp(1, words[0][0], words[0][words[0].size() - 1]);
    }
};
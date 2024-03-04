class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(tokens.begin(), tokens.end());
        const int n = tokens.size();
        int i = 0, j = n - 1;
        int score = 0;
        int ans = 0;
        while (i <= j) {
            if (tokens[i] <= power) {
                power -= tokens[i];
                score++;
                i++;
                ans = max(ans, score);
            }
            else if (score) {
                power += tokens[j];
                score--;
                j--;
            }
            else {
                break;
            }
        }
        return ans;
    }
};
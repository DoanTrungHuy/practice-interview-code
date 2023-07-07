class Solution {
public:
    int helper(string &answerKey, int k, char c) {
        int l = 0, cnt = 0;
        int n = answerKey.size();
        int ans = 0;
        
        for (int r = 0; r < n; r++) {
            if (answerKey[r] == c) {
                cnt++;
            }
            while (cnt > k and l < n) {
                if (answerKey[l] == c) {
                    cnt--;
                }
                l++;
            }
            ans = max(ans, r - l + 1);
        }
        
        return ans;
    }
    int maxConsecutiveAnswers(string answerKey, int k) {
        return max(helper(answerKey, k, 'F'), helper(answerKey, k, 'T'));
    }
};
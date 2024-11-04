class Solution {
public:
    string compressedString(string word) {
        const int n = word.size();
        int cnt = 1;
        string ans = "";
        
        for (int i = 1; i < n; ++i) {
            if (word[i - 1] != word[i]) {
                while (cnt > 9) {
                    ans.append(1, '9');
                    ans.append(1, word[i - 1]);
                    cnt -= 9;
                }
                ans.append(1, char(cnt + '0'));
                ans.append(1, word[i - 1]);
                cnt = 1;
            }
            else {
                cnt++;
            }
        }
        
        while (cnt > 9) {
            ans.append(1, '9');
            ans.append(1, word[n - 1]);
            cnt -= 9;
        }
        ans.append(1, char(cnt + '0'));
        ans.append(1, word[n - 1]);
        cnt = 1;
        
        return ans;
    }
};

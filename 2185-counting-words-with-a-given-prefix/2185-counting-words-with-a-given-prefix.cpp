class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        const int n = pref.size();
        int ans = 0;

        for (string word : words) {
            const int m = word.size();

            if (m < n) {
                continue;
            }

            int j = 0;
            bool flag = true;

            for (char c : pref) {
                if (c != word[j++]) {
                    flag = false;
                    break;
                }
            }

            ans += flag;
        }

        return ans;
    }
};
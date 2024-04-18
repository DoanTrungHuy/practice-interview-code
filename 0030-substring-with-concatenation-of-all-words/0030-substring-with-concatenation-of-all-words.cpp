class Solution {
private:
    string s;
    int k;
    int m;
    
public:
    bool check(int index, unordered_map<string, int> cnt) {
        // cout << "INDEX: " << index << '\n';
        for (int i = index; i < index + k; i += m) {
            string tmp = s.substr(i, m);
            // cout << tmp << '\n';
            cnt[tmp]--;
        }
        for (auto &[key, val] : cnt) {
            if (val != 0) {
                return false;
            }
        }
        return true;
    }
    
    vector<int> findSubstring(string s, vector<string>& words) {
        this->s = s;
        this->m = words[0].size();
        k = 0;
        unordered_map<string, int> cnt;
        for (string word : words) {
            cnt[word]++;
            k += word.size();
        }
        vector<int> ans;
        const int n = s.size();
        for (int i = 0; i < (n - k + 1); ++i) {
            if (check(i, cnt)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
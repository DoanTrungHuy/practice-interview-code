class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        const int n = code.size();
        
        for (int i = 0; i < n; ++i) {
            code.push_back(code[i]);
        }
        
        if (k == 0) {
            vector<int> vi = vector<int>(n, 0);
            return vi;
        }
        
        const int m = code.size();
        vector<int> ans;
        bool flag_neg = false;
        
        if (k < 0) {
            k = -k;
            flag_neg = true;
            reverse(code.begin(), code.end());
        }
        
        int cnt_k = 0;
        for (int i = k; i < m; ++i) {
            cnt_k += k == (i % n);
            if (cnt_k > 1) {
                break;
            }
            int cnt = 0;
            int sum = 0;
            int j = i;
            while (cnt < k) {
                cnt++;
                sum += code[j--];
            }
            ans.push_back(sum);
        }
        
        if (flag_neg) {
            reverse(ans.begin(), ans.end());
        }
        
        return ans;
    }
};
class Solution {
public:
    vector<int> rearrangeBarcodes(vector<int>& barcodes) {
        map<int, int> hash;
        vector<int> v;
        
        for (int code : barcodes) {
            hash[code]++;
        }
        
        for (auto [val, cnt] : hash) {
            v.push_back(val);
        }
        
        sort(v.begin(), v.end(), [&](int a, int b) {
            return hash[a] > hash[b];
        });
        
        int n = barcodes.size();
        vector<int> ans(n, -1);
        int i = 0;
        
        for (int x : v) {
            while (i < n and hash[x] > 0) {
                if (ans[i] == -1) {
                    ans[i] = x;
                }
                i += 2;
                hash[x]--;
                if (i >= n) {
                    i = 1;
                }
            }
        }
        
        return ans;
    }
};
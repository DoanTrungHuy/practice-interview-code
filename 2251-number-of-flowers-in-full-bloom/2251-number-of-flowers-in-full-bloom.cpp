class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        map<int, int> compress;
        
        for (auto flower : flowers) {
            int l = flower[0];
            int r = flower[1];
            compress[l]++;
            compress[r + 1]--;
        }
        
        int times = 0;
        int curr_num_flower = 0;
        
        for (auto &[k, v] : compress) {
            curr_num_flower += v;
            v = curr_num_flower;
        }
        
        const int n = people.size();
        
        vector<int> ans(n);
        
        for (int i = 0; i < n; ++i) {
            auto it = compress.upper_bound(people[i]);
            if (it != compress.begin()) {
                it--;
                ans[i] = it->second;
            }
        }
        
        return ans;
    }
};
class Solution {
public:
    set<int> gen(string num) {
        const int n = num.size();
        set<int> s;
        s.insert(stoi(num));
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(num[i], num[j]);
                s.insert(stoi(num));
                for (int x = 0; x < n; ++x) {
                    for (int y = x + 1; y < n; ++y) {
                        swap(num[x], num[y]);
                        s.insert(stoi(num));
                        swap(num[x], num[y]);
                    }
                }
                swap(num[i], num[j]);
            }
        }
        
        return s;
    }
    
    int countPairs(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        const int n = nums.size();
        unordered_map<int, int> cnt;
        int ans = 0;
        
        for (int i = 0; i < n; ++i) {
            string num = to_string(nums[i]);
            set<int> gen_all_sw = gen(num);
            for (int num_sw : gen_all_sw) {
                ans += cnt[num_sw];
            }
            cnt[nums[i]]++;
        }
        
        return ans;
    }
};
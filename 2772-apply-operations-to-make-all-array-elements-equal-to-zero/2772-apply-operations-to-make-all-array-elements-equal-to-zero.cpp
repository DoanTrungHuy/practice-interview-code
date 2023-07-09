class Solution {
public:
    bool checkArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int, int>> enumer;
        int s = 0, j = 0;

        for (int i = 0; i < n; i++) {
            while (j < enumer.size() and i - enumer[j].first >= k) {
                s -= enumer[j].second;
                j += 1;
            }

            nums[i] -= s;
            
            if (nums[i] != 0) {
                enumer.push_back({i, nums[i]});
                int v = nums[i];
                nums[i] = 0;
                s += v;
            }
            
//             for (int i = 0; i < n; ++i) {
//                 cout << nums[i] << ' ';
//             }
//             cout << '\n';
        }

        while (!enumer.empty() and j < enumer.size() and n - enumer[j].first >= k) {
            j += 1;
        }

        int maxNum = 0;
        
        for (int i = 0; i < n; i++) {
            maxNum = max(maxNum, nums[i]);
        }

        return maxNum == 0 and j == enumer.size();
    }
};
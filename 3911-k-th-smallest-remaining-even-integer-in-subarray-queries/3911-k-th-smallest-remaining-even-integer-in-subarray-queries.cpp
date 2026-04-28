class Solution {
public:
    int calc_gx(vector<int> &nums, vector<int> &pref, int l, int r, int x) {
        const int n = nums.size();
        int left = l;
        int right = r;
        int idx = -1;

        while (left <= right) {
            int mid = (left + right) / 2;

            if (nums[mid] <= x) {
                idx = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }

        if (idx == -1) {
            return 0;
        }

        return pref[idx + 1] - pref[l];
    }

    vector<int> kthRemainingInteger(vector<int>& nums, vector<vector<int>>& queries) {
        const int n = nums.size();

        vector<int> pref(n + 1);

        for (int i = 0; i < n; ++i) {
            pref[i + 1] = pref[i] + !(nums[i]&1);
        }

        vector<int> ans;

        for (auto q : queries) {
            int l = q[0];
            int r = q[1];
            int k = q[2];

            long long left = 1;
            long long right = 1e18;
            long long X = 0;

            while (left <= right) {
                long long mid = (left + right) / 2;

                long long fx = mid / 2;
                long long gx = calc_gx(nums, pref, l, r, mid);

                if (k <= fx - gx) {
                    X = mid;
                    right = mid - 1;
                }
                else {
                    left = mid + 1;
                }
            }

            ans.push_back(X & 1 ? X + 1 : X);
        }

        return ans;
    }
};
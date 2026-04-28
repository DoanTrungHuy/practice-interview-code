class Solution {
public:
    vector<int> kthRemainingInteger(vector<int>& nums, vector<vector<int>>& queries) {
        // 2, 4, 6, 8, 10, 12, 14, 16
        //       --------
        // TH1 (k < l): 2*k
        // TH2 (k > r): (k + count_del)*2
        // Th3 (l <= k <= r): (k + count_del_left)*2

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

            int sum_del = pref[r + 1] - pref[l];

            int left_bound_cnt_even = (nums[l] + 1) / 2;

            if (left_bound_cnt_even > k) {
                ans.push_back(2*k);
                continue;
            }

            int right_bound_cnt_even = nums[r] / 2;

            if (k > right_bound_cnt_even) {
                ans.push_back(2*(k + sum_del));
                continue;
            }

            int lo = 1, hi = 2e9;
            while (lo < hi) {
                int mid = lo + (hi - lo) / 2;
                // Số chẵn trong [2..mid]
                int total = mid / 2;
                // Số chẵn bị xóa trong [nums[l]..nums[r]] mà <= mid
                // dùng pref để đếm số chẵn trong nums[l..r] <= mid
                int left2 = l, right2 = r, deleted = 0;
                // đếm chẵn trong nums[l..r] <= mid
                int pos = upper_bound(nums.begin()+l, 
                                    nums.begin()+r+1, mid) 
                        - nums.begin();
                deleted = pref[pos] - pref[l];
                
                if (total - deleted >= k) hi = mid;
                else lo = mid + 1;
            }
            ans.push_back(lo % 2 == 0 ? lo : lo + 1);

        }

        return ans;
    }
};
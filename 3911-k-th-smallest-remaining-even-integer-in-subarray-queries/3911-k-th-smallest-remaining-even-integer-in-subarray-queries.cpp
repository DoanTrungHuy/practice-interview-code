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

            long long lo = 1, hi = 2e9 + 2e5 + 10;
            while (lo < hi) {
                long long mid = lo + (hi - lo) / 2;
                // Số chẵn trong [2..mid]
                long long total = mid / 2;
                // Số chẵn bị xóa trong [nums[l]..nums[r]] mà <= mid
                // dùng pref để đếm số chẵn trong nums[l..r] <= mid
                // đếm chẵn trong nums[l..r] <= mid
                long long pos = upper_bound(nums.begin()+l, nums.begin()+r+1, mid) - nums.begin();
                
                if (total - (pref[pos] - pref[l]) >= k) {
                    hi = mid;
                }
                else {
                    lo = mid + 1;
                }
            }
            ans.push_back(lo % 2 == 0 ? lo : lo + 1);
        }

        return ans;
    }
};
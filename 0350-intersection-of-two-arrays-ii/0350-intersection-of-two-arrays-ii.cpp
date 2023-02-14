class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int cnt[1001] = {0};
        bool check[1001] = {false};
        
        for (int num : nums1) {
            cnt[num]++;
            check[num] = true;
        }
        
        vector<int> ans;
        
        for (int num : nums2) {
            if (check[num] and cnt[num]) {
                ans.push_back(num);
                --cnt[num];
            }
        }
        
        return ans;
    }
};
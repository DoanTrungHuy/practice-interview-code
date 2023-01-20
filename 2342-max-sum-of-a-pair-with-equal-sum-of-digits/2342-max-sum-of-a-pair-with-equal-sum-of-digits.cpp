class Solution {
public:
    int maximumSum(vector<int>& nums) {
        unordered_map<int, vector<int>> um;
        for (int num : nums) {
            int totalDigit = 0;
            int dummy = num;
            while (dummy > 0) {
                totalDigit += dummy % 10;
                dummy /= 10;
            }
            um[totalDigit].push_back(num); 
        }
        int res = 0;
        for (auto it : um) {
            vector<int> v = it.second;
            int n = v.size();
            int vj = v[0];
            int maxTwoSum = 0;
            for (int i = 1; i < n; ++i) {
                maxTwoSum = max(maxTwoSum, v[i] + vj);
                vj = max(vj, v[i]);
            }
            res = max(res, maxTwoSum);
        }
        return res == 0 ? -1 : res;
    }
};
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

class Solution {
public:
    vector<int> findXSum(vector<int>& nums, int k, int x) {
        const int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> um;
        long long s = 0;

        tree<pair<int, int>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> os;

        auto calc = [&]() {
            long long xSum = 0;
            int cnt = 0;
            for (auto it = os.rbegin(); it != os.rend() && cnt < x; ++it) {
                xSum += static_cast<long long>(it->first) * it->second;
                cnt++;
            }
            return xSum;
        };

        for (int j = 0, i = 0; i < n; i++) {
            if (um[nums[i]] > 0) {
                os.erase({um[nums[i]], nums[i]});
            }
            
            um[nums[i]]++;
            os.insert({um[nums[i]], nums[i]});
            s += nums[i];
            
            if (i - j + 1 == k) {
                ans.push_back(calc());
                
                os.erase({um[nums[j]], nums[j]});
                um[nums[j]]--;
                
                if (um[nums[j]] > 0) {
                    os.insert({um[nums[j]], nums[j]});
                }
                
                s -= nums[j];
                j++;
            }
        }

        return ans;
    }
};

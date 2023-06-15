using ll = long long;

class Solution {
public:
    vector<long long> maximumSegmentSum(vector<int>& nums, vector<int>& removeQueries) {
        int n = nums.size();
        vector<ll> prefix(n + 1, 0);
        
        for (int i = 0; i < n; ++i) {
            prefix[i + 1] = prefix[i] + nums[i];
        }
        
        vector<ll> ans;
        
        set<int> removeIdx;
        removeIdx.insert(0);
        removeIdx.insert(n + 1);
        
        multiset<ll> maxSegmentSum;
        maxSegmentSum.insert(prefix[n]);
        
        for (int idx : removeQueries) {
            idx++;
            auto upper = removeIdx.lower_bound(idx);
            auto lower = prev(upper);
            
            int hi = *upper;
            int lo = *lower;
            
            ll sumOld = prefix[hi - 1] - prefix[lo];
            ll sum1 = prefix[idx - 1] - prefix[lo];
            ll sum2 = prefix[hi - 1] - prefix[idx];
            
            maxSegmentSum.erase(maxSegmentSum.lower_bound(sumOld));
            maxSegmentSum.insert(sum1);
            maxSegmentSum.insert(sum2);
            
            ans.push_back(*maxSegmentSum.rbegin());
            
            removeIdx.insert(idx);
        }
        
        return ans;
    }
};
class FenwickTree {
private:
    vector<int> bit;
    int n;
    
public:
    FenwickTree(int n = 0) {
        bit.resize(n + 1);
        this->n = n;
    }
    
    void update(int i, int v) {
        for (i = i + 1; i <= n; i += -i&i) {
            bit[i] += v;
        }
    }
    
    int count(int i) {
        int s = 0;
        for (i = i + 1; i > 0; i -= -i&i) {
            s += bit[i];
        }
        return s;
    }
};

class Solution {
public:
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> um;
        const int n = nums1.size();
        
        for (int i = 0; i < n; ++i) {
            um[nums2[i]] = i; 
        }
        
        vector<int> mapping(n);
        
        for (int i = 0; i < n; ++i) {
            mapping[i] = um[nums1[i]];
        }
        
        vector<int> left_smaller(n), right_larger(n);
        
        FenwickTree ft[2];
        
        ft[0] = FenwickTree(n);
        ft[1] = FenwickTree(n);
        
        for (int i = 0; i < n; ++i) {
            left_smaller[i] = ft[0].count(mapping[i] - 1);
            ft[0].update(mapping[i], 1);
        }
        
        for (int i = n - 1; i >= 0; --i) {
            right_larger[i] = ft[1].count(n - 1) - ft[1].count(mapping[i]);
            ft[1].update(mapping[i], 1);
        }
        
        long long ans = 0;
        
        for (int i = 0; i < n; ++i) {
            ans += 1LL*left_smaller[i]*right_larger[i];
        }
        
        return ans;
    }
};
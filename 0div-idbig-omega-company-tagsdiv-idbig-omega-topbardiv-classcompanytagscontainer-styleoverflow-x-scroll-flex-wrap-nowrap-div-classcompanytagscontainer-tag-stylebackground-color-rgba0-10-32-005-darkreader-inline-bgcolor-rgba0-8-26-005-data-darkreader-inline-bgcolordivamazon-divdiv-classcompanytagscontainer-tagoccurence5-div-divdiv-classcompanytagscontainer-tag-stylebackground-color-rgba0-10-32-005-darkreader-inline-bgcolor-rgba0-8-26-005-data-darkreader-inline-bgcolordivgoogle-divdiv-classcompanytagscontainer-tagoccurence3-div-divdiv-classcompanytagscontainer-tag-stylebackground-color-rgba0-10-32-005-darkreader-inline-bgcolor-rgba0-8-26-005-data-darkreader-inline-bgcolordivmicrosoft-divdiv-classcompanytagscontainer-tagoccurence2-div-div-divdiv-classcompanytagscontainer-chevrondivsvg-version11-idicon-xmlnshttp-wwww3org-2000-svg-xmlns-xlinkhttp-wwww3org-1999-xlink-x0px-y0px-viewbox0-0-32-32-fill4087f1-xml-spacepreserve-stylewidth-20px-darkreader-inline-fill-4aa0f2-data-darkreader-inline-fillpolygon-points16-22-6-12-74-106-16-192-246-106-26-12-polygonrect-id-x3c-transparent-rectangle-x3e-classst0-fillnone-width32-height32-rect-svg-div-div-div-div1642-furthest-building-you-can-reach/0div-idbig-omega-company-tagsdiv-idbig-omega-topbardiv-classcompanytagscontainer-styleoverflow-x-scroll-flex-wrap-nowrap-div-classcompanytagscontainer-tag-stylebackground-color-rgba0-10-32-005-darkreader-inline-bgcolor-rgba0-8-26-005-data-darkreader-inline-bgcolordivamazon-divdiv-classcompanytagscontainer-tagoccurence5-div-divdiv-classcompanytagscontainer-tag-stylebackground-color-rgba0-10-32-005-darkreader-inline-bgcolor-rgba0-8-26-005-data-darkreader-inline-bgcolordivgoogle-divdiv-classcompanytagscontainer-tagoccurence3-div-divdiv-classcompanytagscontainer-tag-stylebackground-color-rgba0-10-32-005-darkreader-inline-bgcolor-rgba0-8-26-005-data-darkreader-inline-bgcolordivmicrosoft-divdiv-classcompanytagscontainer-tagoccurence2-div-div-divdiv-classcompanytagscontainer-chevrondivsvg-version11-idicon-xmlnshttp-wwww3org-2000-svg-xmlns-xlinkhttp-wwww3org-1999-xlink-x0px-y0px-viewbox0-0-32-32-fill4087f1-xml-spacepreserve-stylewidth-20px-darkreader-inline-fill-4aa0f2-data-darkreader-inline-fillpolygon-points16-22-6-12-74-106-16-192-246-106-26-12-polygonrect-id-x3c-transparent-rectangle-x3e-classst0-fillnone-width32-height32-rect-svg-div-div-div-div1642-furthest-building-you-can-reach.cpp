class Solution {
public:
    bool is_valid(vector<int> &heights, int bricks, int ladders, int mid) {
        priority_queue<int> pq;
        
        for (int i = 0; i < mid; ++i) {
            if (heights[i + 1] - heights[i] <= 0) {
                continue;
            }
            pq.push(heights[i + 1] - heights[i]);
        }
        
        while (!pq.empty() and ladders) {
            pq.pop();
            ladders--;
        }
        
        if (pq.empty()) {
            return true;
        }
        
        while (!pq.empty()) {
            bricks -= pq.top();
            pq.pop();
        }
        
        return bricks >= 0;
    }
    
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        const int n = heights.size();
        int left = 0, right = n - 1;
        int ans = 0;
        
        while (left <= right) {
            int mid = (left + right) / 2;
            
            if (is_valid(heights, bricks, ladders, mid)) {
                ans = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        
        return ans;
    }
};
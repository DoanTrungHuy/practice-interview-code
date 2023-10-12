/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        const int n = mountainArr.length();
        int left = 0;
        int right = n - 1;
        int peak = 0;
        
        while (left <= right) {
            int mid = (left + right) >> 1;
            
            int y1 = mountainArr.get(mid);
            int y2 = mountainArr.get(mid + 1);
            
            if (y1 <= y2) {
                peak = mid;
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        
        // CASE 1
        {
            int left = 0;
            int right = peak;
        
            while (left <= right) {
                int mid = (left + right) >> 1;
                
                int can_pick = mountainArr.get(mid);
                
                if (can_pick == target) {
                    return mid;
                }

                if (can_pick < target) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
        }
        
        // CASE 2
        {
            int left = peak + 1;
            int right = n - 1;
        
            while (left <= right) {
                int mid = (left + right) >> 1;
                
                int can_pick = mountainArr.get(mid);
                
                if (can_pick == target) {
                    return mid;
                }

                if (can_pick > target) {
                    left = mid + 1;
                }
                else {
                    right = mid - 1;
                }
            }
        }
        
        return -1;
    }
};
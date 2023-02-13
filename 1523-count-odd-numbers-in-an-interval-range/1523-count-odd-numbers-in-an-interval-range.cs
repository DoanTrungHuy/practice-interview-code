public class Solution {
    public int CountOdds(int low, int high) {
        int cnt = 0;
        for (int i = low; i <= high; ++i) {
            cnt += (i & 1);
        }
        return cnt;
    }
}
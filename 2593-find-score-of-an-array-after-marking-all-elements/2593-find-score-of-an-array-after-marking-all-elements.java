import java.util.*;

class Solution {
    public long findScore(int[] nums) {
        final int n = nums.length;
        long score = 0;

        PriorityQueue<int[]> minHeap = new PriorityQueue<>((a, b) -> {
            if (a[0] == b[0]) {
                return Integer.compare(a[1], b[1]);
            }
            return Integer.compare(a[0], b[0]);
        });

        for (int i = 0; i < n; i++) {
            minHeap.offer(new int[]{nums[i], i});
        }

        Set<Integer> marked = new HashSet<>();

        while (!minHeap.isEmpty()) {
            int[] current = minHeap.poll();
            int value = current[0];
            int index = current[1];

            if (marked.contains(index)) {
                continue;
            }

            score += value;

            marked.add(index);
            
            if (index > 0) {
                marked.add(index - 1);
            }
            
            if (index < n - 1) {
                marked.add(index + 1);
            }
        }

        return score;
    }
}

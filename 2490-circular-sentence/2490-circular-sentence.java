class Solution {
    public boolean isCircularSentence(String sentence) {
        String a[] = sentence.split(" ");
        final int n = a.length;
        
        if (a[0].charAt(0) != a[n - 1].charAt(a[n - 1].length() - 1)) {
            return false;
        }
        
        for (int i = 0; i < n - 1; ++i) {
            int next_i = i + 1;
            char last_idx_of_i = a[i].charAt(a[i].length() - 1);
            char head_idx_of_next_i = a[next_i].charAt(0);
            
            if (last_idx_of_i != head_idx_of_next_i) {
                return false;
            }
        }
        
        return true;
    }
}
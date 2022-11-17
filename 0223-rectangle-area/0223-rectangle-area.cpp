class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        
        int left_boundary = max(ax1, bx1);
        int right_boundary = min(ax2, bx2);
        
        int top_boundary = min(ay2, by2);
        int bottom_bondary = max(ay1, by1);
        
        
        int area_1 = (ax2 - ax1)*(ay2 - ay1);
        int area_2 = (bx2 - bx1)*(by2 - by1);
        int intersection = 0;
        
        if( (left_boundary < right_boundary) && (bottom_bondary < top_boundary)) {
            intersection = ( right_boundary - left_boundary ) * ( top_boundary - bottom_bondary );
        }

        
        return area_1 + area_2 - intersection;
    }
};
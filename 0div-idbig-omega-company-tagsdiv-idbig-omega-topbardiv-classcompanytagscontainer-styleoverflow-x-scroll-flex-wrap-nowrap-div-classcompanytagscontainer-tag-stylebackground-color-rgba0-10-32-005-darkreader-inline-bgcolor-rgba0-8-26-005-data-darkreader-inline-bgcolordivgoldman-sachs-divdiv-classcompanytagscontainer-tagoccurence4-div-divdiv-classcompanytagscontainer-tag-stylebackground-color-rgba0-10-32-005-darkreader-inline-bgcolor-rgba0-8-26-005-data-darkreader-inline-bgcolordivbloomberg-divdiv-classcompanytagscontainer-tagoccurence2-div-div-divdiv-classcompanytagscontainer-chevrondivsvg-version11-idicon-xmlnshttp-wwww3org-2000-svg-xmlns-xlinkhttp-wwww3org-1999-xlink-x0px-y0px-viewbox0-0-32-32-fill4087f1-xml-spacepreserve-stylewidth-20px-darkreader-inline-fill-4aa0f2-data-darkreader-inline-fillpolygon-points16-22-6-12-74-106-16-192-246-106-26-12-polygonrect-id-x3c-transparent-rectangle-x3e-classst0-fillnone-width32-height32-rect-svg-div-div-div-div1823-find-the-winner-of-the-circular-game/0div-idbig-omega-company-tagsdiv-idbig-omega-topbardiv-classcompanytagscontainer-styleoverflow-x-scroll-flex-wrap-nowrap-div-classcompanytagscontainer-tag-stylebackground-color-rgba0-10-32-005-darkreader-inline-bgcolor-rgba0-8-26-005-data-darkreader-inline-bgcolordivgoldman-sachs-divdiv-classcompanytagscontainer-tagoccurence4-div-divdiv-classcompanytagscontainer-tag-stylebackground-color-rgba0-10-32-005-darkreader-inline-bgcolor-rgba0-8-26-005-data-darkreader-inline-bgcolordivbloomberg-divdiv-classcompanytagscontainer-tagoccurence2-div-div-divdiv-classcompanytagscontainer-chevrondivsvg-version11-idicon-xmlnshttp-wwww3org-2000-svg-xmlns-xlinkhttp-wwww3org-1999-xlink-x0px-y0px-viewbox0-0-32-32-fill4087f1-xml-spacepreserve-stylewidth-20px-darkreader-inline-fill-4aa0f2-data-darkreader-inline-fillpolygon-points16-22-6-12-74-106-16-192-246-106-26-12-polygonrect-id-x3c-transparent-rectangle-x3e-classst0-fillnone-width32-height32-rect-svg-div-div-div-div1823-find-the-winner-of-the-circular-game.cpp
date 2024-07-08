#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<class T> using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;

class Solution {
public:
    int findTheWinner(int n, int k) {
        ordered_set<int> os;
        
        for (int i = 1; i <= n; ++i) {
            os.insert(i);
        }
        
        k--;
        int i = k%n;
        
        while (os.size() > 1) {
            auto it = os.find_by_order(i);
            os.erase(it);
            i = (i + k) % os.size();
        }
        
        return *os.begin();
    }
};
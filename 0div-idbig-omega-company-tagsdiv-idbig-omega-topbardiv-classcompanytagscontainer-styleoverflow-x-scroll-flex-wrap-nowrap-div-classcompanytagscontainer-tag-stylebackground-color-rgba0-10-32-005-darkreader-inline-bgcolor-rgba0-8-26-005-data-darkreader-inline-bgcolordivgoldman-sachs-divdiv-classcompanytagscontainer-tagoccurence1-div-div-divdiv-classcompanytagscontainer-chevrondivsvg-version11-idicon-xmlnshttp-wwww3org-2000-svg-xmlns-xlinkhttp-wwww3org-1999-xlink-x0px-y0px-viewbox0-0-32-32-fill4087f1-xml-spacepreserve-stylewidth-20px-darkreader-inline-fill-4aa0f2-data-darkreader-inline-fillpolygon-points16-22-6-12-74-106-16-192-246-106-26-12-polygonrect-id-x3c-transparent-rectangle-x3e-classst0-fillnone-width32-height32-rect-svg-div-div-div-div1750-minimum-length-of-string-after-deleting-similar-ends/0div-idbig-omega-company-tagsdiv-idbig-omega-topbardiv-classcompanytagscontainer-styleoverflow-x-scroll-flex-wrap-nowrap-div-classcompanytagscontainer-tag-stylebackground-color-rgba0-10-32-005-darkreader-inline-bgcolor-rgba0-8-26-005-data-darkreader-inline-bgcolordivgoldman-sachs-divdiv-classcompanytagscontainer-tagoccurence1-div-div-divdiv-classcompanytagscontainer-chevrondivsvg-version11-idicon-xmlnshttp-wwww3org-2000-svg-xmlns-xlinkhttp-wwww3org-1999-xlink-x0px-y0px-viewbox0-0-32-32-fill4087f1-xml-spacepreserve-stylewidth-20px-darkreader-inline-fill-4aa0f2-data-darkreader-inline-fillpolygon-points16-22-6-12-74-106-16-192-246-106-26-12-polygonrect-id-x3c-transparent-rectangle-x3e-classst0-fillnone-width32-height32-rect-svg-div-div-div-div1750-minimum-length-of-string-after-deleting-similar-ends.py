class Solution:
    def minimumLength(self, s: str) -> int:
        lst = []
        
        for v, c in groupby(s):
            lst.append((v, len(list(c))))
        
        N = len(lst)
        i, j = 0, N - 1
        cnt_del_ele = 0
        
        while i <= j:
            if lst[i][0] == lst[j][0]:
                if i != j:
                    cnt_del_ele += lst[i][1] + lst[j][1]
                else:
                    if lst[i][1] > 1:
                        cnt_del_ele += lst[i][1]
            else:
                break
            i += 1
            j -= 1
        
        return len(s) - cnt_del_ele
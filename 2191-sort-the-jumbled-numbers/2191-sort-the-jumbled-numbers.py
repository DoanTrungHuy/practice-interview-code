class Solution:
    def sortJumbled(self, mapping: List[int], nums: List[int]) -> List[int]:
        nums = [(str(num), i) for i, num in enumerate(nums)]
        mapp = dict()
        
        tmp = []
        
        for num, i in nums:
            mapp[i] = int(num)
            s = []
            for c in num:
                s.append(chr(mapping[ord(c) - ord('0')] + ord('0')))
            tmp.append((int("".join(s)), i))
                
        tmp.sort()
        
        ans = []
        
        for num, i in tmp:
            ans.append(mapp[i])
        
        return ans
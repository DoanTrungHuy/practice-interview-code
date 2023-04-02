class Solution:
    def makeSubKSumEqual(self, arr: List[int], k: int) -> int:
        n = len(arr)
        bucket = defaultdict(list)
        lengthBucket = gcd(n, k)
        
        for i in range(n):
            bucket[i % lengthBucket].append(arr[i])
            
        ans = 0
        
        for _, l in bucket.items():
            l.sort()
            m = len(l)
            med = m // 2
            ans += sum([abs(l[med] - l[i]) for i in range(m)])
            
        return ans
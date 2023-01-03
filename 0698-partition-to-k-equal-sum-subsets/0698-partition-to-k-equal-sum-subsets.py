class Solution:
    def canPartitionKSubsets(self, nums: List[int], k: int) -> bool:
        if len(nums) < k or sum(nums) % k != 0 or max(nums) > sum(nums) // k:
            return False
        target = sum(nums)//k

        nums.sort(reverse = True)
        edge = [0]*k

        def dfs(index):
            if index == len(nums):
                return True
            seen = [] # record the searched summ
            for i in range(k):
                if edge[i] in seen: continue
                if edge[i] + nums[index] <= target:
                    seen.append(edge[i])
                    edge[i] += nums[index]
                    if dfs(index + 1):
                        return True
                    edge[i] -= nums[index]
            return False

        return dfs(0)
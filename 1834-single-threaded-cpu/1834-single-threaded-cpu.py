class Solution:
    def getOrder(self, tasks: List[List[int]]) -> List[int]:
        # 1--2
        #    2-------6
        #      3----5
        #         4-5

        # -> 0 2 3 1

        n = len(tasks)
        tasks = sorted([(tasks[i][0], tasks[i][1], i) for i in range(n)])

        heap = []
        ans = []
        time = tasks[0][0]
        i = 0

        while len(ans) < n:
            while i < n and tasks[i][0] <= time:
                heappush(heap, (tasks[i][1], tasks[i][2]))
                i += 1

            if heap:
                timeNext, idx = heappop(heap)
                time += timeNext
                ans.append(idx)
            else:
                time = tasks[i][0]

        return ans

class Solution:
    def minNumberOfSeconds(self, mountainHeight: int, workerTimes: list[int]) -> int:
        def can_finish_in_time(max_time: int) -> bool:
            total_reduction = 0

            for wt in workerTimes:
                left, right = 0, mountainHeight
                max_reduction = 0

                while left <= right:
                    mid = (left + right) // 2
                    time_needed = wt * mid * (mid + 1) // 2
                    if time_needed <= max_time:
                        max_reduction = mid
                        left = mid + 1
                    else:
                        right = mid - 1

                total_reduction += max_reduction
                if total_reduction >= mountainHeight:
                    return True

            return total_reduction >= mountainHeight

        left, right = 0, 10**18
        best_time = 0

        while left <= right:
            mid = (left + right) // 2
            if can_finish_in_time(mid):
                best_time = mid
                right = mid - 1
            else:
                left = mid + 1

        return best_time

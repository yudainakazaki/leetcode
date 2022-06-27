from typing import List

class Solution:
    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        res = []
        for interval in intervals:
            if ((newInterval[0] <= interval[1] and interval[1] <= newInterval[1]) 
                or (newInterval[0] <= interval[0] and interval[0] <= newInterval[1])
                or (interval[0] <= newInterval[0] and newInterval[1] <= interval[1])):
                    newInterval[0] = min(newInterval[0], interval[0])
                    newInterval[1] = max(newInterval[1], interval[1])
            else:
                res.append(interval)

        res.append(newInterval)
        res.sort()

        return res
            
def main():

    n = int(input())
    intervals = []
    for i in range(n):
        interval = list(map(int, input().strip().split()))
        intervals.append(interval)
    newInterval = list(map(int, input().strip().split()))

    s = Solution()
    print(s.insert(intervals, newInterval))

if __name__ == "__main__":
    main()
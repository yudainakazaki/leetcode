from typing import List
from xml.etree.ElementInclude import include

class Solution:
    def rob(self, nums):
       
        if not nums:
            return 0

        if len(nums) == 1:
            return nums[0]

        curMax, prevMax = 0, 0
        for i in range(len(nums)-1):
            temp = curMax
            curMax = max(curMax, prevMax + nums[i])
            prevMax = temp
        record = curMax

        curMax, prevMax = 0, 0
        for i in range(len(nums)-1, 0, -1):
            temp = curMax
            curMax = max(curMax, prevMax + nums[i])
            prevMax = temp

        return max(record, curMax)

def main():
    nums = list(map(int, input().strip().split()))
    s = Solution()
    print(s.rob(nums))


if __name__ == "__main__":
    main()
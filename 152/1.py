from typing import List

class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        res = max(nums)
        curMin, curMax = 1, 1
        for n in nums:
            if n == 0:
                curMin, curMax = 1, 1
                continue
            
            temp = curMax * n
            curMax = max(temp, n * curMin, n)
            curMin = min(temp, n * curMin, n)
            res = max(res, curMax)
        return res


def main():

    nums = list(map(int, input().strip().split()))
    s = Solution()
    print(s.maxProduct(nums))

if __name__ == "__main__":
    main()
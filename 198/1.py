from typing import List

class Solution:
    def rob(self, nums: List[int]) -> int:
        track = {-2:0, -1:0}
            
        res = 0
        for i, num in enumerate(nums):
            curMax = 0
            for j in range(-2, i-1):
                curMax = max(curMax, track[j])
            track[i] = num + curMax
            res = max(res, track[i])
            
        return res

def main():
    nums = list(map(int, input().strip().split()))
    s = Solution()
    print(s.rob(nums))


if __name__ == "__main__":
    main()
from typing import List

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:

        s = set(nums)
        res = 0

        for num in s:
            if num-1 not in s:
                length = 0
                while num+length in s:
                    length += 1
                res = max(length, res)

        return res


def main():
    nums = list(map(int, input().strip().split()))
    s = Solution()
    print(s.longestConsecutive(nums))

if __name__ == "__main__":
    main()
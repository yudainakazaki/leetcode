from typing import List

class Solution:
    def containsDuplicate(self, nums: List[int]) -> bool:
        res = False
        s = set()
        for num in nums:
            if(num in s):
                res = True
                break
            s.add(num)

        return res


def main():
    nums = list(map(int, input().strip().split()))
    s = Solution()
    print(s.containsDuplicate(nums))


if __name__ == "__main__":
    main()
from typing import List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        map = {};
        res = [];

        for i in range(len(nums)):
            if(target-nums[i] in map.keys()):    
                res = {map.get(target-nums[i]), i}
                break
            map[nums[i]] = i
               
        return res


def main():
    n = int(input())
    nums = list(map(int,input().strip().split())) 
    target = int(input())
    solution = Solution()
    res = solution.twoSum(nums, target)
    print(res);

    
if __name__ == "__main__":
    main()

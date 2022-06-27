from typing import List

class Solution:

    def backtrack(self, cur : List[int], pos : int, target : int):
        if target == 0:
            self.res.append(cur.copy())
        if target <= 0:
            return 
        
        prev = -1
        for i in range(pos, len(self.candidates)):
            if self.candidates[i] == prev:
                continue
            cur.append(self.candidates[i])
            self.backtrack(cur, i+1, target-self.candidates[i])
            cur.pop()
            prev = self.candidates[i]

    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()

        self.res = []
        self.candidates = candidates.copy()
        
        self.backtrack([], 0, target)
        return self.res

def main():

    nums = list(map(int,input().strip().split()))
    target = int(input())

    s = Solution()
    print(s.combinationSum2(nums, target))

if __name__ == "__main__":
    main()

        
from termios import OFDEL

class Solution:
    def climbStairs(self, n: int) -> int:
        dp = {0:1}
        for i in range(1,n+1):
            dp[i] = 0
            if(i-1 >= 0):
                dp[i] += dp[i-1]
            if(i-2 >= 0):
                dp[i] += dp[i-2]
            
        return dp[n]

def main():
    n = int(input())
    s = Solution()
    print(s.climbStairs(n))

if __name__ == "__main__":
    main()
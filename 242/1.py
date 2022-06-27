class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        return sorted(s) == sorted(t)


def main():
    str1 = input()
    str2 = input()
    s = Solution()
    print(s.isAnagram(str1, str2))


if __name__ == "__main__":
    main()
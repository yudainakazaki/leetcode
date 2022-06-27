class Solution:
    def isAnagram(self, s: str, t: str) -> bool:

        if(len(s) != len(t)): 
            return False

        hm1 = {}
        for char in s:
            if(char in hm1.keys()): hm1[char] += 1
            else: hm1[char] = 1

        hm2 = {}
        for char in t:
            if(char in hm2.keys()): hm2[char] += 1
            else: hm2[char] = 1

        for key in hm1:
            if(key not in hm2.keys() or hm1[key] != hm2[key]):
                return False

        return True


def main():
    str1 = input()
    str2 = input()
    s = Solution()
    print(s.isAnagram(str1, str2))


if __name__ == "__main__":
    main()
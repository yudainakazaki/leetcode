from collections import deque

class Solution:
    def isValid(self, s: str) -> bool:
        stack = deque()
        for char in s:
            if char == '(' or char == '{' or char == '[':
                stack.append(char)
            else:
                if not stack: return False
                if char == ')' and stack.pop() != '(': return False
                elif char == '}' and stack.pop() != '{': return False
                elif char == ']' and stack.pop() != '[': return False
            
        return not stack

def main():
    s = input()
    solution = Solution()
    print(solution.isValid(s))

if __name__ == "__main__":
    main()
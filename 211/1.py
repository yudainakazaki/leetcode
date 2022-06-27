from xmlrpc.client import Boolean

class WordDictionary:

    s = set()
    
    def __init__(self):
        self.s = {}

    def addWord(self, word: str) -> None:
        self.s.add(word)

    def checkEquality(self, word1, word2) -> bool:
        if len(word1) != len(word2): return False
        for i in range(len(word1)):
            if word1[i] != '.' and word1[i] != word2[i]:
                return False
        return True

    def search(self, word: str) -> bool:
        if not self.s: return False
        if word in self.s: return True
        if '.' in word: 
            for w in self.s:
                if(self.checkEquality(word, w)): return True  
        return False
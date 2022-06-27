class TrieNode:
    def __init__(self):
        self.children = {}
        self.endOfWord = False 

class Trie:
    
    def __init__(self):
        self.root = TrieNode()

    def insert(self, word: str) -> None:
        cur = self.root
        for c in word:
            if c not in cur.children:
                cur.children[c] = TrieNode()
            cur = cur.children[c]
        cur.endOfWord = True

    def search(self, word: str) -> bool:
        cur = self.root
        for c in word:
            if c not in cur.children:
                return False
            cur = cur.children[c]
        
        return cur.endOfWord

    def startsWith(self, prefix: str) -> bool:
        cur = self.root

        for c in prefix:
            if c not in cur.children:
                return False
            cur = cur.children[c]
        return True

def main():
    
    while True:
        args = list(input().strip().split())
        command = args[0]
        if len(args) == 2:
            argument = args[1]
        
        if command == "Trie":
            trie = Trie()
            print("Instantiated trie")
        elif command == "insert":
            trie.insert(argument)
        elif command == "search":
            print(trie.search(argument))
        elif command == "startWith":
            print(trie.startsWith(argument))
        elif command == "done":
            break
        else:
            print("Invalid command.")
            continue

if __name__ == "__main__":
    main()    
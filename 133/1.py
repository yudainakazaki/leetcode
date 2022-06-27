class Node:
    def __init__(self, val = 0, neighbors = None):
        self.val = val
        self.neighbors = neighbors if neighbors is not None else []

class Solution:

    def defs(self, node):
        if node in self.oldToNew:
            return self.oldToNew[node]

        copy = Node(node.val)
        self.oldToNew[node] = copy
        for nei in node.neighbors:
            copy.neighbors.append(self.dfs(nei))
        return copy

    def cloneGraph(self, node: 'Node') -> 'Node':
        self.oldToNew = {}
        return self.dfs(node) if node else None


def main():
    adjList = [[2,4],[1,3],[2,4],[1,3]]
    nodes = {}
    for i in range(len(adjList)):
        node = Node(i+1, [])
        nodes[i+1] = node

    for i in range(len(adjList)):
        for adj in adjList[i]:
            nodes[i+1].neighbors.append(nodes[adj])

    s = Solution()
    s.cloneGraph(nodes[1])
    for i in nodes:
        print(nodes[i].val)
        print(str(nodes[i].neighbors[0].val) + " , " + str(nodes[i].neighbors[1].val))

if __name__ == "__main__":
    main()

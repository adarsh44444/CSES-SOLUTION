from collections import deque

class Solution:
    def collectTheCoins(self, coins, edges):
        n = len(coins)
        graph = [set() for _ in range(n)]
        for u, v in edges:
            graph[u].add(v)
            graph[v].add(u)

        total = len(edges) * 2
        removed = 0
        queue = deque()

        for i in range(n):
            if len(graph[i]) == 1 and coins[i] == 0:
                queue.append(i)

        while queue:
            current = queue.popleft()
            if not graph[current]:
                continue
            neighbor = next(iter(graph[current]))
            graph[neighbor].discard(current)
            graph[current].discard(neighbor)
            removed += 2
            if len(graph[neighbor]) == 1 and coins[neighbor] == 0:
                queue.append(neighbor)

        for i in range(n):
            if len(graph[i]) == 1:
                queue.append(i)

        for _ in range(2):
            for _ in range(len(queue)):
                node = queue.popleft()
                if not graph[node]:
                    continue
                parent = next(iter(graph[node]))
                graph[parent].discard(node)
                graph[node].discard(parent)
                removed += 2
                if len(graph[parent]) == 1:
                    queue.append(parent)

        return total - removed

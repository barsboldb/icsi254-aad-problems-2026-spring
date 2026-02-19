from collections import defaultdict

def brute_force_solution(n, m, edges, x, a):
    # Build adjacency list
    graph = defaultdict(list)
    for u, v in edges:
        graph[u].append(v)
        graph[v].append(u)

    max_survivors = 0

    def dfs(node, current_soldiers, visited):
        nonlocal max_survivors

        # Fight in this room
        if current_soldiers > a[node - 1]:
            remaining = current_soldiers
        else:
            remaining = current_soldiers // 2

        # If nobody survives
        if remaining == 0:
            return

        # If reached destination
        if node == n:
            max_survivors = max(max_survivors, remaining)
            return

        # Explore neighbors
        for neighbor in graph[node]:
            if neighbor not in visited:
                visited.add(neighbor)
                dfs(neighbor, remaining, visited)
                visited.remove(neighbor)

    # Start DFS from room 1
    dfs(1, x, set([1]))

    return max_survivors

import GraphGenerator as GG
from collections import deque
import copy
def path_capacity(graph, path):
    # Initialize capacity to infinity
    # For each edge in the path
    capacity = 0
    for (u, v) in path:
        # Update capacity if edge capacity is smaller
        capacity += graph[u][v]
    return capacity

def successive_shortest_path(graph, capacity, cost, source, sink):
    def bellman_ford():
        dist = [float('inf')] * len(graph)
        dist[source] = 0
        parent = [-1] * len(graph)

        for _ in range(len(graph) - 1):
            for u in range(len(graph)):
                for v in range(len(graph[u])):
                    if capacity[u][v] > 0 and dist[u] + cost[u][v] < dist[v]:
                        dist[v] = dist[u] + cost[u][v]
                        parent[v] = u

        return dist, parent

    def augment(path):
        min_capacity = float('inf')

        for u, v in path:
            min_capacity = min(min_capacity, capacity[u][v])

        for u, v in path:
            capacity[u][v] -= min_capacity
            capacity[v][u] += min_capacity

        return min_capacity

    max_flow = 0
    total_cost = 0
    min_cost_path = None

    while True:
        dist, parent = bellman_ford()

        if dist[sink] == float('inf'):
            break  # No more augmenting paths
        path = []
        v = sink

        while v != source:
            u = parent[v]
            path.append((u, v))
            v = u

        path.reverse()

        flow = augment(path)
        max_flow += flow
        total_cost += flow * dist[sink]

        # Update min_cost_path if the current path has a lower cost
        if min_cost_path is None or total_cost < min_cost_path[1]:
            min_cost_path = (path, total_cost)

    return max_flow, min_cost_path[1], min_cost_path[0]


nR = 3
nC = 3

comp = GG.GraphGenerator(num_rows= nR, num_cols= nC)

graph = comp.compute_adjacency_matrix()
# print("Adjacency Matrix:")
# print(graph)
capacity, cost = comp.compute_adjacency_matrices()
capacity1 = copy.deepcopy(capacity)
cost1 = copy.deepcopy(cost)
print("Capacity Matrix:")
print(capacity)
print("Cost Matrix:")
print(cost)

source, sink = 0, nR * nC - 1
max_flow, total_cost, min_cost_path = successive_shortest_path(graph, capacity, cost, source, sink)

path_capacity1 = path_capacity(capacity1, min_cost_path)  # Calculate the capacity of the path
path_cost1 = path_capacity(cost1, min_cost_path)  # Calculate the cost of the path
print(f"The minimum cost maximum flow from {source} to {sink}: {path_cost1}, path capacity: {path_capacity1} ")
print(f"Shortest Path with Minimum Cost: {min_cost_path}")
comp.visualize_random_grid()

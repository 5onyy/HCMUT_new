import networkx as nx
import matplotlib.pyplot as plt
import random

class GraphGenerator:
    def compute_adjacency_matrices(self):
        num_nodes = len(self.graph_instance.nodes())
        capacity_matrix = [[0 for _ in range(num_nodes)] for _ in range(num_nodes)]
        cost_matrix = [[0 for _ in range(num_nodes)] for _ in range(num_nodes)]

        for u, v, data in self.graph_instance.edges(data=True):
            capacity_matrix[u][v] = data['capacity']
            cost_matrix[u][v] = data['cost']

        return capacity_matrix, cost_matrix
    
    def compute_adjacency_matrix(self):
        adjacency_matrix = nx.adjacency_matrix(self.graph_instance)
        return adjacency_matrix.toarray()

    def __init__(self, num_rows, num_cols):
        self.num_rows = num_rows
        self.num_cols = num_cols
        self.graph_instance = self.generate_random_grid()

    def generate_random_grid(self, capacity_range=(1, 10), cost_range=(1, 5)):
        random_grid = nx.DiGraph()
        nodes_list = [i * self.num_cols +
                      j for i in range(self.num_rows) for j in range(self.num_cols)]
        random_grid.add_nodes_from(nodes_list)

        for i in nodes_list:
            if i % self.num_cols < self.num_cols - 1:
                random_grid.add_edge(
                    i, i + 1, capacity=random.randint(*capacity_range), cost=random.randint(*cost_range))

            if i // self.num_cols < self.num_rows - 1:
                random_grid.add_edge(
                    i, i + self.num_cols, capacity=random.randint(*capacity_range), cost=random.randint(*cost_range))

        return random_grid

    def visualize_random_grid(self):
        positions = {node: ((node % self.num_cols), -(node // self.num_cols))
                      for node in self.graph_instance.nodes()}
        dr_op = {
            "font_size": 10,
            "node_size": 650,
            "node_color": "lightblue",
            "edgecolors": "brown",
            "linewidths": 2,
            "width": 1,
        }
        nx.draw(self.graph_instance, positions, with_labels=True, **dr_op)
        edge_labels = {(u, v): f"({d['capacity']},{d['cost']})" for (
            u, v, d) in self.graph_instance.edges(data=True)}
        nx.draw_networkx_edge_labels(
            self.graph_instance, positions, edge_labels=edge_labels, font_size=6)
        plt.show()

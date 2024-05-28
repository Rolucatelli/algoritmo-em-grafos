import sys
import networkx as nx
import matplotlib.pyplot as plt

def read_adjacency_matrix(file_path):
    with open(file_path, 'r') as file:
        lines = file.readlines()[1:]  # Ignorar a primeira linha
        adjacency_matrix = [[int(x) for x in line.split()] for line in lines]
    return adjacency_matrix

def read_closeness(file_path):
    with open(file_path, 'r') as file:
        closeness_values = [float(line.strip()) for line in file]
    return closeness_values

def create_graph(adjacency_matrix):
    G = nx.Graph()
    for i in range(len(adjacency_matrix)):
        for j in range(len(adjacency_matrix[i])):
            if adjacency_matrix[i][j] != 0:
                G.add_edge(i, j, weight=adjacency_matrix[i][j])
    return G

if len(sys.argv) != 2:
    print("Usage: python script.py input_file")
    sys.exit(1)

input_file = sys.argv[1]
adjacency_matrix_file = f"./exe/grafos/{input_file}"
closeness_file = f"./exe/output/{input_file}"

adjacency_matrix = read_adjacency_matrix(adjacency_matrix_file)
closeness_values = read_closeness(closeness_file)

G = create_graph(adjacency_matrix)

max_closeness = max(closeness_values)
node_colors = [plt.cm.Reds(1 - (c / max_closeness)) for c in closeness_values]

pos = nx.spring_layout(G)
nx.draw(G, pos, node_color=node_colors, with_labels=True)
plt.title('Grafo com Cores Baseadas na Diferença de Closeness')
plt.show()

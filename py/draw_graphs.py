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

# Ler a matriz de adjacência do arquivo
adjacency_matrix_file = "./exe/grafos/grafo_1.txt"
adjacency_matrix = read_adjacency_matrix(adjacency_matrix_file)

# Ler os valores de closeness do arquivo
closeness_file = "./exe/output/grafo_1.txt"
closeness_values = read_closeness(closeness_file)

# Criar o grafo a partir da matriz de adjacência
G = create_graph(adjacency_matrix)

# Mapear os valores de closeness para cores (quanto maior closeness, mais claro é o grafo)
max_closeness = max(closeness_values)
node_colors = [plt.cm.Reds(1 - (c / max_closeness)) for c in closeness_values]

# Desenhar o grafo
pos = nx.spring_layout(G)  # Posicionamento dos nós
nx.draw(G, pos, node_color=node_colors, with_labels=True)
plt.title('Grafo com Cores Baseadas na Diferença de Closeness')
plt.show()
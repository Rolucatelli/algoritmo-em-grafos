import os
import random

def create_graph_file(num_vertices, num_file):
    name_file = f"graph_{num_file}.txt"

    with open(name_file, "w") as File:
        File.write(f"{num_vertices}\n")  # Escreve o tamanho da matriz na primeira linha
        for i in range(num_vertices):
            line = [random.randint(1, 20) if j != i else 0 for j in range(num_vertices)]  # Ajusta a diagonal para 0
            formatted_line = " ".join(map(str, line))
            File.write(f"{formatted_line}\n")

    print(f"Arquivo '{name_file}' criado com sucesso.")

def create_graphs(num_graphs, num_vertices):
    num_file = 1
    for i in range(1, num_graphs + 1):
        create_graph_file((20 + (i*5)), num_file)
        num_file += 1

num_graphs = 10
num_vertices = 75

create_graphs(num_graphs, num_vertices)
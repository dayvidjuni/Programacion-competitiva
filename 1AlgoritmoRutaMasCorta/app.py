from flask import Flask, request, jsonify, render_template
import math

class Edge:
    def __init__(self, target: str, weight: float):
        self.target = target
        self.weight = weight

class Node:
    def __init__(self, name: str, lat: float, lon: float):
        self.name = name
        self.lat = lat
        self.lon = lon
        self.edges = []

    def add_edge(self, target: str, weight: float):
        self.edges.append(Edge(target, weight))

class Graph:
    def __init__(self):
        self.nodes = {}

    def add_node(self, name: str, lat: float, lon: float):
        if name not in self.nodes:
            self.nodes[name] = Node(name, lat, lon)

    def add_connection(self, u: str, v: str, w: float):
        self.nodes[u].add_edge(v, w)
        self.nodes[v].add_edge(u, w)

    def get_shortest_path(self, start: str, end: str):
        if start not in self.nodes or end not in self.nodes:
            return [], 0

        distances = {node: math.inf for node in self.nodes}
        previous = {node: None for node in self.nodes}
        distances[start] = 0
        unvisited = list(self.nodes.keys())

        while unvisited:
            current_node = min(unvisited, key=lambda node: distances[node])
            if distances[current_node] == math.inf or current_node == end:
                break
            unvisited.remove(current_node)

            for edge in self.nodes[current_node].edges:
                if edge.target in unvisited:
                    new_dist = distances[current_node] + edge.weight
                    if new_dist < distances[edge.target]:
                        distances[edge.target] = new_dist
                        previous[edge.target] = current_node

        path = []
        current = end
        while current is not None:
            path.append(current)
            if current == start:
                break
            current = previous[current]

        if not path or path[-1] != start:
            return [], 0

        path.reverse()
        return path, distances[end]

app = Flask(__name__)
peru_graph = Graph()

data_nodes = {
    "Amazonas": (-6.23, -77.86), "Ancash": (-9.53, -77.53), "Apurimac": (-13.63, -72.88),
    "Arequipa": (-16.41, -71.54), "Ayacucho": (-13.16, -74.22), "Cajamarca": (-7.16, -78.51),
    "Callao": (-12.05, -77.12), "Cusco": (-13.52, -71.97), "Huancavelica": (-12.78, -74.97),
    "Huanuco": (-9.93, -76.24), "Ica": (-14.07, -75.73), "Junin": (-12.06, -75.21),
    "La Libertad": (-8.11, -79.02), "Lambayeque": (-6.77, -79.84), "Lima": (-12.04, -77.04),
    "Loreto": (-3.75, -73.25), "Madre de Dios": (-12.59, -69.18), "Moquegua": (-17.20, -70.93),
    "Pasco": (-10.66, -76.25), "Piura": (-5.19, -80.63), "Puno": (-15.84, -70.02),
    "San Martin": (-6.03, -76.97), "Tacna": (-18.01, -70.25), "Tumbes": (-3.56, -80.45),
    "Ucayali": (-8.38, -74.55)
}

for city, coords in data_nodes.items():
    peru_graph.add_node(city, coords[0], coords[1])

peru_graph.add_connection("Tumbes", "Piura", 280)
peru_graph.add_connection("Piura", "Lambayeque", 210)
peru_graph.add_connection("Piura", "Cajamarca", 350)
peru_graph.add_connection("Lambayeque", "Cajamarca", 260)
peru_graph.add_connection("Lambayeque", "La Libertad", 200)
peru_graph.add_connection("La Libertad", "Cajamarca", 300)
peru_graph.add_connection("La Libertad", "Amazonas", 450)
peru_graph.add_connection("La Libertad", "San Martin", 480)
peru_graph.add_connection("La Libertad", "Huanuco", 520)
peru_graph.add_connection("La Libertad", "Ancash", 440)
peru_graph.add_connection("Ancash", "Huanuco", 320)
peru_graph.add_connection("Ancash", "Lima", 400)
peru_graph.add_connection("Lima", "Callao", 15)
peru_graph.add_connection("Lima", "Huanuco", 410)
peru_graph.add_connection("Lima", "Pasco", 250)
peru_graph.add_connection("Lima", "Junin", 310)
peru_graph.add_connection("Lima", "Huancavelica", 440)
peru_graph.add_connection("Lima", "Ica", 300)
peru_graph.add_connection("Ica", "Huancavelica", 200)
peru_graph.add_connection("Ica", "Ayacucho", 380)
peru_graph.add_connection("Ica", "Arequipa", 700)
peru_graph.add_connection("Arequipa", "Ayacucho", 620)
peru_graph.add_connection("Arequipa", "Apurimac", 350)
peru_graph.add_connection("Arequipa", "Cusco", 510)
peru_graph.add_connection("Arequipa", "Puno", 300)
peru_graph.add_connection("Arequipa", "Moquegua", 220)
peru_graph.add_connection("Moquegua", "Puno", 260)
peru_graph.add_connection("Moquegua", "Tacna", 155)
peru_graph.add_connection("Tacna", "Puno", 380)
peru_graph.add_connection("Cajamarca", "Amazonas", 330)
peru_graph.add_connection("Amazonas", "San Martin", 350)
peru_graph.add_connection("Amazonas", "Loreto", 500)
peru_graph.add_connection("San Martin", "Huanuco", 400)
peru_graph.add_connection("San Martin", "Loreto", 600)
peru_graph.add_connection("San Martin", "Ucayali", 550)
peru_graph.add_connection("Huanuco", "Pasco", 100)
peru_graph.add_connection("Huanuco", "Ucayali", 380)
peru_graph.add_connection("Pasco", "Junin", 140)
peru_graph.add_connection("Pasco", "Ucayali", 300)
peru_graph.add_connection("Junin", "Huancavelica", 140)
peru_graph.add_connection("Junin", "Ayacucho", 320)
peru_graph.add_connection("Junin", "Cusco", 450)
peru_graph.add_connection("Junin", "Ucayali", 350)
peru_graph.add_connection("Huancavelica", "Ayacucho", 240)
peru_graph.add_connection("Ayacucho", "Apurimac", 250)
peru_graph.add_connection("Ayacucho", "Cusco", 580)
peru_graph.add_connection("Apurimac", "Cusco", 190)
peru_graph.add_connection("Cusco", "Ucayali", 600)
peru_graph.add_connection("Cusco", "Madre de Dios", 480)
peru_graph.add_connection("Cusco", "Puno", 390)
peru_graph.add_connection("Loreto", "Ucayali", 750)
peru_graph.add_connection("Ucayali", "Madre de Dios", 650)
peru_graph.add_connection("Madre de Dios", "Puno", 550)

@app.route('/')
def home():
    return render_template('index.html')

@app.route('/calculate', methods=['POST'])
def calculate_route():
    data = request.get_json()
    start_node = data.get('start')
    end_node = data.get('end')
    
    path, distance = peru_graph.get_shortest_path(start_node, end_node)
    
    coordinates = []
    for city in path:
        node = peru_graph.nodes[city]
        coordinates.append({"lat": node.lat, "lon": node.lon, "name": city})
        
    return jsonify({
        "path": path,
        "distance": distance,
        "coordinates": coordinates
    })

if __name__ == '__main__':
    app.run(debug=True, port=5000)
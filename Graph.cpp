#include "Graph.hpp"

Graph::Graph() { this->_size = 0; }

void Graph::addVertex(std::string name) {
  if (this->_size + 1 >= (int)_edges.size()) {
    int size = _edges.size();
    _edges.resize(size == 0 ? 1 : size * 2);
  }

  std::unique_ptr<Node> n(new Node(this->_size, name));

  // push to the vector of vertices
  this->_vertices.push_back(std::move(n));
  ++this->_size;
}

void Graph::addEdge(int sourceId, int destinationId, int cost) {
  // Edge has a pointer to the node and the cost
  std::unique_ptr<Edge> e(new Edge(destinationId, cost));
  this->_edges[sourceId].push_back(std::move(e));
}

void Graph::displayVertices() {
  for (int i = 1; i < _size; ++i) {
    std::cout << "(" << i << ") " << _vertices[i]->name << std::endl;
  }
}

struct EdgeHistory {
  int cost, previous;
  EdgeHistory() { this->cost = std::numeric_limits<int>::max(); }
  EdgeHistory(int cost, int previous) {
    this->cost = cost;
    this->previous = previous;
  }
};

class EdgeComparator {
public:
  int operator()(const Edge &e1, const Edge &e2) { return e1.cost > e2.cost; }
};

std::stack<std::string> Graph::shortestPath(int sourceId, int destinationId) {
  std::priority_queue<Edge, std::vector<Edge>, EdgeComparator> minHeap;
  std::vector<EdgeHistory> distances(this->_size);

  minHeap.push(Edge(sourceId, 0));
  distances[sourceId] = EdgeHistory(0, -1);

  while (!minHeap.empty()) {
    int minId = minHeap.top().id;
    minHeap.pop();
    for (auto &i : _edges[minId]) {
      int nextId = i->id;
      int nextCost = i->cost;
      if (distances[nextId].cost > distances[minId].cost + nextCost) {
        distances[nextId] =
            EdgeHistory(distances[minId].cost + nextCost, minId);
        minHeap.push(Edge(nextId, distances[nextId].cost));
      }
    }
  }

  // Creating output
  std::stack<std::string> output;
  EdgeHistory curr = distances[destinationId];

  if (distances[destinationId].cost == std::numeric_limits<int>::max()) {
    output.push("No Path Found");
    return output;
  }

  output.push("Distance: " + std::to_string(distances[destinationId].cost) +
              "m");
  output.push(_vertices[destinationId]->name);
  while (curr.previous > 0) {
    output.push(_vertices[curr.previous]->name);
    curr = distances[curr.previous];
  }
  return output;
}

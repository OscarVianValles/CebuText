#ifndef GRAPH_HPP
#define GRAPH_HPP

#include "Edge.hpp"
#include "Node.hpp"
#include <iostream>
#include <limits>
#include <memory>
#include <queue>
#include <stack>
#include <vector>

class Graph {
private:
  std::vector<std::unique_ptr<Node>> _vertices;
  std::vector<std::vector<std::unique_ptr<Edge>>> _edges;
  int _cap;
  int _size;
  void _expand();

public:
  Graph();
  void addVertex(std::string);
  void addEdge(int, int, int);
  void displayVertices();
  std::stack<std::string> shortestPath(int, int);
};

#endif

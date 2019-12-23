#ifndef NODE_HPP
#define NODE_HPP

#include <string>
class Node {
public:
  int id;
  std::string name;
  Node(int, std::string);
  Node(const Node &);
};

#endif

#ifndef MAP_HPP
#define MAP_HPP

#include "Graph.hpp"

class Map {
private:
  Graph _graphMorning;
  Graph _graphEvening;
  Graph *_currGraph;
  void _loadMap();

public:
  Map();
  void displayChoices();
  void changeTime(int);
  void addLandmark(std::string);
  void addRoad(int, int, int, int);
  std::stack<std::string> getPath(int, int);
};

#endif

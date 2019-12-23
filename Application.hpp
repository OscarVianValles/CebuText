#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include "Map.hpp"

class Application {
private:
  Map _cebu;
  void displayChoices();

public:
  void run();
  void getPath(int, int);
};

#endif

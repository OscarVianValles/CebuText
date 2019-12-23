#include "Application.hpp"

void Application::run() {
  std::string a, b;
  int source, destination;
  while (true) {
    std::cout << "=====================" << std::endl
              << "|     Main Menu     |" << std::endl
              << "=====================" << std::endl
              << "(1) Get Shortest Path" << std::endl
              << "(2) Change Time" << std::endl
              << "(3) Quit" << std::endl;
    std::cin >> a;

    if (a == "1") {
      displayChoices();
      std::cout << "Select Source Location and Destination Location"
                << std::endl
                << "Source ID: ";
      std::cin >> source;
      std::cout << "Destination ID: ";
      std::cin >> destination;
      std::cout << std::endl;
      getPath(source, destination);
    } else if (a == "2") {
      std::cout << "Enter an integer representing a time from 0 to 24"
                << std::endl;
      std::cout << "New Time: ";
      std::cin >> source;
      _cebu.changeTime(source);
      std::cout << "Time has been changed" << std::endl;
    } else if (a == "3") {
      return;
    }
  }
}
void Application::displayChoices() { _cebu.displayChoices(); }

void Application::getPath(int sourceId, int destinationId) {
  std::stack<std::string> path = _cebu.getPath(sourceId, destinationId);
  std::cout << std::endl;
  while (path.size() >= 1) {
    std::cout << path.top() << std::endl;
    path.pop();
  }

  std::cout << std::endl;
}

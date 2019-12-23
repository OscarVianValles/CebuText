#include "Application.hpp"

void Application::run() {
  std::string a, b;
  int source, destination, morningCost, eveningCost;
  while (true) {
    std::cout << "=====================" << std::endl
              << "|     Main Menu     |" << std::endl
              << "=====================" << std::endl
              << "(1) Get Shortest Path" << std::endl
              << "(2) Change Time" << std::endl
              << "(3) Add Landmark" << std::endl
              << "(4) Add Roads" << std::endl
              << "(5) Quit" << std::endl;
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
      std::cout << "Enter the name of the new landmark" << std::endl
                << "Landmark Name: ";
      std::cin >> b;
      std::cout << "Please note, no new roads have been made to connect to "
                   "this landmark"
                << std::endl;
      _cebu.addLandmark(b);
    } else if (a == "4") {
      displayChoices();
      std::cout << "Enter the Source Location and Destination Location of the "
                   "new Road"
                << std::endl
                << "Source ID: ";
      std::cin >> source;
      std::cout << "Destination ID: ";
      std::cin >> destination;
      std::cout << "Enter the distance in the morning from these two locations"
                << std::endl;
      std::cin >> morningCost;
      std::cout << "Enter the distance in the evening from these two locations"
                << std::endl;
      std::cin >> eveningCost;
      std::cout << std::endl;
      _cebu.addRoad(source, destination, morningCost, eveningCost);
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

#include "zlasdtest/test.hpp"



#include "container/container.hpp"

/* ************************************************************************** */

#include <iostream>

/* ************************************************************************** */

int main() {
    std::cout << "Lasd Libraries 2024" << std::endl;

    unsigned int scelta = 0;
    bool continua = true;

    while(continua){

      std::cout << std::endl << "MENU:" << std::endl;
      std::cout << std::endl << "1. Avviare Lasd Test";
      std::cout << std::endl << "2. Esci" << std::endl;

      std::cin >> scelta;

        switch (scelta) {
          case 1:
              lasdtest();
              break;
          default:
              std::cout << std::endl << "Goodbye" << std::endl;
              continua = false;
              break;
      }

    }

    return 0;
}
#include <iostream>

#include "Timer.hpp"

int main(){
  
  Timer timer;
  timer.start();

  long long i = 0;
  while (i < 10000000000) {
    i++;
  }

  timer.stop();
  std::cout << timer.sec() << std::endl;
}

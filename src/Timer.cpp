#include "Timer.hpp"

void Timer::start(){
  StartTime = std::chrono::system_clock::now();
  running = true;
}

void Timer::stop(){
  StopTime = std::chrono::system_clock::now();
  running = false;
}

float Timer::milli(){
  std::chrono::time_point<std::chrono::system_clock> endTime;

  if (running == true){
    endTime = std::chrono::system_clock::now();
  }
  else {
    endTime = StopTime;
  }
  
  return std::chrono::duration_cast<std::chrono::milliseconds>(endTime - StartTime).count();
}

float Timer::sec(){
  return milli() / 1000.0;
}

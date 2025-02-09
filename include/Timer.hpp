#include <iostream>
#include <chrono>

class Timer{
public:
  void start();
  void stop();

  float milli();
  float sec();

private:
    std::chrono::time_point<std::chrono::system_clock> StartTime, StopTime;
    bool running = false;

};

#include <chrono>

class Timer{
public:
  void start();
  void stop();

  float milli();
  float sec();

private:
    std::chrono::time_point<std::chrono::system_clock> m_StartTime, m_StopTime;
    bool m_bRunning = false;

};

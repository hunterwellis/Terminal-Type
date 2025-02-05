#include "Timer.hpp"

void Timer::start(){
  m_StartTime = std::chrono::system_clock::now();
  m_bRunning = true;
}

void Timer::stop(){
  m_StopTime = std::chrono::system_clock::now();
  m_bRunning = false;
}

float Timer::milli(){
  std::chrono::time_point<std::chrono::system_clock> endTime;

  if (m_bRunning == true){
    endTime = std::chrono::system_clock::now();
  }
  else {
    endTime = m_StopTime;
  }
  
  return std::chrono::duration_cast<std::chrono::milliseconds>(endTime - m_StartTime).count();
}

float Timer::sec(){
  return milli() / 1000.0;
}

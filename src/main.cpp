#include <iostream>
#include <cstdlib>
#include <pthread.h>

#include "Timer.hpp"
#include "SentenceGenerator.hpp"
#include "KeyIO.hpp"

static std::string vtos(std::vector<std::string> vec){

  std::string str = "";
  for (size_t i = 0; i < vec.size(); i++) {
    str += vec[i] + " ";
  }
  str.pop_back();
  return str;
}

int main(int argc, char *argv[]){
  
  Timer timer;
  SentenceGenerator senGen;
  KeyIO keyio;

  std::string refSentence;
  std::string inputString = "";

  // reference text
  int size = (argc > 1) ? std::atoi(argv[1]) : 10;
  refSentence = vtos(senGen.generate(size));
  std::string command = "cowsay \"" + refSentence + "\"";
  std::system(command.c_str());

  keyio.setRawMode();

  // countdown
  timer.start();
  float time = timer.sec(); 
  float timeSec = 0;

  while (timeSec < 6){
    time = timer.sec();
    if (time - timeSec > 1){
      timeSec++;
      std::cout << "\x1b[A\b \b" << 6-timeSec << std::endl;
    }
  }
  std::cout << "\x1b[A\b \bGO!" << std::endl;

  // check/display text
  int index = 0;
  char keyInput;

  timer.start();
  while(refSentence != inputString){
    keyInput = keyio.getKeystroke();

    if (keyInput == refSentence[index]){
      inputString += keyInput;
      std::cout << "\033[32m" << keyInput << "\033[0m";
      index++;
    }
    else if (keyInput == 127){
      inputString.pop_back();
      std::cout << "\b \b";
      index--;
    }
    else {
      inputString += keyInput;
      std::cout << "\033[31m" << keyInput << "\033[0m";
      index++;
    }
  }

  //calculate results
  timer.stop();
  keyio.restoreTerminal();
  std::cout << std::endl << "WPM: " << 60*(size/timer.sec()) << std::endl;
  std::cout << "WPM (avg): " << 60*((refSentence.size()/4.7)/timer.sec()) << std::endl;
}


#include "SentenceGenerator.hpp"

std::vector<std::string> SentenceGenerator::generate(int size){

  for (int i = 0; i < size; i++) {
    sentence.push_back(uniqueValue(sentence));
  }
  return sentence;
}

void SentenceGenerator::print(){

  for (unsigned long i = 0; i < sentence.size(); i++) {
    std::cout << sentence[i] << " ";
  }
  std::cout << std::endl;
}

std::string SentenceGenerator::uniqueValue(std::vector<std::string> exVec){
  // generate random index
  std::mt19937 generator(std::random_device{}());
  std::uniform_int_distribution<int> distribution(0, dictionary.size() - 1);

  std::string val = dictionary[distribution(generator)];

  auto it = std::find(exVec.begin(), exVec.end(), val);
  if (it == exVec.end()){
    // string not in vector
    return val;
  }
  else return uniqueValue(exVec);
}

#include "../include/PushdownAutomaton.h"
#include <iostream>

int main(int argc, char* argv[]) {
  std::string file_name = argv[1];
  PushdownAutomaton automaton(file_name);
  std::string test_string = argv[2];
  std::cout << (automaton.exec(test_string)? "Si pertenece al lenguaje" : "No pertenece al lenguaje") << '\n';

  return argc;
}
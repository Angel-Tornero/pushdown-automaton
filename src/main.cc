#include "../include/PushdownAutomaton.h"

int main(int argc, char* argv[]) {
  std::string file_name = argv[1];
  PushdownAutomaton automaton(file_name);

  return argc;
}
#include "../include/State.h"

State::State(std::string id) {
  id_ = id;
}

void State::addTransition(std::pair<char, char> symbols, std::pair<State*,std::vector<char>> destiny) {
  transition_function_[symbols].insert(destiny);
}
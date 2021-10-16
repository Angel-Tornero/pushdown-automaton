#include "../include/State.h"

State::State(std::string id) {
  id_ = id;
}

void State::addTransition(std::pair<std::string, std::string> symbols, std::pair<State*,std::vector<std::string>> destiny) {
  transition_function_[symbols].insert(destiny);
}
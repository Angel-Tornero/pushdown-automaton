#include "../include/State.h"

State::State(std::string id) {
  id_ = id;
}

void State::addTransition(std::pair<char, char> symbols, std::pair<State*,std::vector<char>> destiny) {
  transition_function_[symbols].insert(destiny);
}

std::set<std::pair<State*, std::vector<char>>> State::transitionFunction(char tape_symbol, char stack_symbol) {
  return transition_function_[std::make_pair(tape_symbol, stack_symbol)];
}
/**
 * @file State.cc
 * @author Ángel Tornero Hernández
 * @brief Universidad de La Laguna
 * @brief Escuela Superior de Ingeniería y Tecnología
 * @brief Grado en Ingeniería Informática
 * @brief Complejidad Computacional
 * @version 1.0
 * @date 2021-10-21
 * 
 */


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
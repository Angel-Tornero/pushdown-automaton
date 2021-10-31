/**
 * @file Stack.cc
 * @author Ángel Tornero Hernández
 * @brief Universidad de La Laguna
 * @brief Escuela Superior de Ingeniería y Tecnología
 * @brief Grado en Ingeniería Informática
 * @brief Complejidad Computacional
 * @version 1.0
 * @date 2021-10-21
 * 
 */


#include "../include/Stack.h"
#include <iostream>

Stack::Stack(char initial_symbol) {
  initial_symbol_ = initial_symbol;
  stack_.push_back(initial_symbol);
}

char Stack::top() {
  if (stack_.size() > 0) return stack_.back();
  return ' ';
}

void Stack::push(char c) {
  stack_.push_back(c);
}

void Stack::pop() {
  if (stack_.size() > 0) stack_.pop_back();
}

bool Stack::empty() {
  return (stack_.size() == 0? true : false);
}

std::string Stack::to_string() {
  std::string string;
  for (int i = (int)stack_.size() - 1; i >= 0; i--) {
    string.push_back(stack_[i]);
  }
  return string;
}

#include "../include/Stack.h"

Stack::Stack(std::string initial_symbol) {
  stack_.push_back(initial_symbol);
}

std::string Stack::top() {
  return stack_.back();
}

void Stack::push(std::string c) {
  stack_.push_back(c);
}

void Stack::pop() {
  stack_.pop_back();
}
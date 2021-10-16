#include "../include/Stack.h"
#include <iostream>

Stack::Stack(char initial_symbol) {
  stack_.push_back(initial_symbol);
}

char Stack::top() {
  if (stack_.size() > 0) return stack_.back();
  return '.';
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

std::ostream& Stack::operator<<(std::ostream& os) {
  os << "[ ";
  for (auto symbol: stack_) {
    os << symbol << ' ';
  }
  os << "<- HEAD";
  return os;
}
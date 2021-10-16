#include "../include/Alphabet.h"
#include <iostream>

Alphabet::Alphabet(std::set<char> symbols) {
  symbols_ = symbols;
}

bool Alphabet::contain(char element) {
  return (symbols_.find(element) != symbols_.end());
}

std::ostream& Alphabet::operator<<(std::ostream& os) {
  os << "Alphabet = { ";
  for (auto symbol: symbols_) os << symbol << ' ';
  os << '}';
  return os;
}
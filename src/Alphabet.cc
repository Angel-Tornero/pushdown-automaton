#include "../include/Alphabet.h"

Alphabet::Alphabet(std::set<std::string> symbols) {
  symbols_ = symbols;
}

bool Alphabet::contain(std::string element) {
  return (symbols_.find(element) != symbols_.end());
}
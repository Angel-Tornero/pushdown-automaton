/**
 * @file Alphabet.cc
 * @author Ángel Tornero Hernández
 * @brief Universidad de La Laguna
 * @brief Escuela Superior de Ingeniería y Tecnología
 * @brief Grado en Ingeniería Informática
 * @brief Complejidad Computacional
 * @version 1.0
 * @date 2021-10-21
 * 
 */


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
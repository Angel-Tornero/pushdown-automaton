/**
 * @file Alphabet.h
 * @author Ángel Tornero Hernández
 * @brief Universidad de La Laguna
 * @brief Escuela Superior de Ingeniería y Tecnología
 * @brief Grado en Ingeniería Informática
 * @brief Complejidad Computacional
 * @version 1.0
 * @date 2021-10-21
 * 
 */

#include <string>
#include <set>

/**
 * @class Alphabet
 * 
 */
class Alphabet {
  private:
    friend class PushdownAutomaton;
    std::set<char> symbols_;
  
  public:
    Alphabet(std::set<char> symbols);
    /**
     * @brief Check if the alphabet contains the given character
     * @param c char
     * @returns bool
     * 
     */
    bool contain(char c);
    /**
     * @brief Operator <<
     * @param os
     * 
     * @return std::ostream&
     */
    std::ostream& operator<<(std::ostream& os);
};
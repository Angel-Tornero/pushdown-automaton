/**
 * @file Stack.h
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
#include <vector>

/**
 * @class Stack (for stack automaton)
 * 
 */
class Stack {
  private:
    friend class PushdownAutomaton;

    std::vector<char> stack_;
    char initial_symbol_;

  public:
    Stack(char initial_symbol);
    /**
     * @brief Get the top symbol of the stack
     * @return char
     * 
     */
    char top();
    /**
     * @brief Push a symbol to the stack
     * @param c char
     * 
     */
    void push(char c);
    /**
     * @brief Remove top element
     * 
     */
    void pop();
    /**
     * @brief Checks if the stack is empty
     * 
     * @return true 
     * @return false 
     */
    bool empty();
    /**
     * @brief Return the stack formatted in a tring
     * 
     * @return string
     */
    std::string to_string();
};
/**
 * @file State.h
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
#include <utility>
#include <map>
#include <set>
#include <vector>

#ifndef _STATE_
#define _STATE_

/**
 * @class State
 * 
 */
class State {
  private:
    friend class PushdownAutomaton;
    std::string id_;
    std::map<std::pair<char, char>, std::set<std::pair<State*,std::vector<char>>>> transition_function_;
    
    /**
     * @brief Return the transitions given a tape symbol and a stack symbol
     * @param tape_symbol
     * @param stack_symbol
     * 
     * @return std::set<std::pair<State*, std::vector<char>>>
     */
    std::set<std::pair<State*, std::vector<char>>> transitionFunction(char tape_symbol, char stack_symbol);
    /**
     * @brief Add a transition to the transition function of the State
     * @param symbols
     * @param destiny
     */
    void addTransition(std::pair<char, char> symbols, std::pair<State*,std::vector<char>> destiny);
    State(std::string id);    
};


#endif
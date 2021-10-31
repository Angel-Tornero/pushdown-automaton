/**
 * @file PushdownAutomaton.h
 * @author Ángel Tornero Hernández
 * @brief Universidad de La Laguna
 * @brief Escuela Superior de Ingeniería y Tecnología
 * @brief Grado en Ingeniería Informática
 * @brief Complejidad Computacional
 * @version 1.0
 * @date 2021-10-21
 * 
 */

#include "Alphabet.h"
#include "Stack.h"
#include "State.h"
#include <set>
#include <map>
#include <fstream>

/**
 * @class PushdownAutomaton (por vaciado)
 * 
 */
class PushdownAutomaton {
  private:
    Alphabet* tape_alphabet_;
    Alphabet* stack_alphabet_;
    Stack* stack_;
    std::set<State*> Q_;
    State* initial_state_;
    bool accepted_string_;

    /**
     * @brief Parse the alphabet in the input file
     * @param file
     * @param option
     */
    void parseAlphabet(std::ifstream& file, int option);
    /**
     * @brief Parse the transition function in the input file
     * @param file
     * @param state_map
     */
    void parseTransitionFunction(std::ifstream& file, std::map<std::string, State*>& state_map);
    /**
     * @brief Recursive function to recognize strings
     * @param string
     * @param current
     * @param pushing_array
     * @param trace
     * @param output_file
     * 
     * @return bool
     */
    bool recursiveExec(std::string string, State* current, std::vector<char> pushing_array, bool trace, std::ofstream& output_file);

  public:
    PushdownAutomaton(std::string& file_name);
    ~PushdownAutomaton();
    /**
     * @brief Parse the automaton given an input file
     * @param file_name
     */
    void parse(std::string& file_name);
    /**
     * @brief Checks if the automaton recognizes the given string
     * @param string
     * @param trace
     * @param output_file
     */
    bool exec(std::string string, bool trace, std::ofstream& output_file);
};
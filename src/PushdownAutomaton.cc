/**
 * @file PushdownAutomaton.cc
 * @author Ángel Tornero Hernández
 * @brief Universidad de La Laguna
 * @brief Escuela Superior de Ingeniería y Tecnología
 * @brief Grado en Ingeniería Informática
 * @brief Complejidad Computacional
 * @version 1.0
 * @date 2021-10-21
 * 
 */


#include "../include/PushdownAutomaton.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <utility>
#include <iterator>

const int TAPE = 1;
const int STACK = 2;

PushdownAutomaton::PushdownAutomaton(std::string& file_name) {
  parse(file_name);
}

PushdownAutomaton::~PushdownAutomaton() {
  delete tape_alphabet_;
  delete stack_alphabet_;
  delete stack_;
  for (auto element: Q_) delete element;
}

std::set<std::string> tokenizerToString(std::string& s) {
    std::stringstream ss(s);
    std::string word;
    std::set<std::string> set;
    while (ss >> word) {
        set.insert(word);
    }
    return set;
}

std::set<char> tokenizerToChar(std::string& s) {
    std::stringstream ss(s);
    char word;
    std::set<char> set;
    while (ss >> word) {
        set.insert(word);
    }
    return set;
}


std::ifstream openInputFile(std::string& file_name) {
  std::ifstream in_file(file_name);
  if (in_file.fail()) {
    std::cout << "No existe el archivo.\n";
    throw -1;
  }
  return in_file;
}

void PushdownAutomaton::parse(std::string& file_name) {
  std::ifstream in_file = openInputFile(file_name);
  std::string temp_string;
  do {
    std::getline(in_file, temp_string);
    if (temp_string[0] == '#') std::cout << temp_string << '\n';
  } while (temp_string[0] == '#');

  //Conjunto Q
  std::set<std::string> states = tokenizerToString(temp_string);
  std::map<std::string, State*> state_map;
  for (auto element: states) {
    State* new_state = new State(element);
    state_map[element] = new_state;
    Q_.insert(new_state);
  }

  //Alfabeto de cinta
  parseAlphabet(in_file, TAPE);

  //Alfabeto de pila
  parseAlphabet(in_file, STACK);

  //Estado inicial
  std::getline(in_file, temp_string);
  initial_state_ = state_map[temp_string];

  //Simbolo inicial de la pila
  std::getline(in_file, temp_string);
  if (!stack_alphabet_->contain(temp_string[0])) throw "Caracter erróneo.";
  stack_ = new Stack(temp_string[0]);

  //Funcion de transición
  parseTransitionFunction(in_file, state_map);
}

void PushdownAutomaton::parseAlphabet(std::ifstream& file, int option) {
  std::string temp;
  std::getline(file, temp);
  std::set<char> alphabet = tokenizerToChar(temp);
  alphabet.insert('.');
  switch (option) {
    case TAPE:
      tape_alphabet_ = new Alphabet(alphabet);
      break;
    case STACK:
      stack_alphabet_ = new Alphabet(alphabet);
      break;
  }
}

void PushdownAutomaton::parseTransitionFunction(std::ifstream& file, std::map<std::string, State*>& state_map) {
  std::string temp, start_state, finish_state;
  char tape_symbol, pop, push;
  std::vector<char> push_vector;
  while (std::getline(file, temp)) {
    std::istringstream iss(temp);
    iss >> start_state;
    iss >> tape_symbol;
    if (!tape_alphabet_->contain(tape_symbol)) throw "Caracter erróneo.";
    iss >> pop;
    if (!stack_alphabet_->contain(pop)) throw "Caracter erróneo.";
    iss >> finish_state;
    push_vector.clear();
    while (iss >> push) {
      if (!stack_alphabet_->contain(push)) throw "Caracter erróneo.";
      push_vector.push_back(push);
    }
    state_map[start_state]->addTransition(std::make_pair(tape_symbol, pop), std::make_pair(state_map[finish_state], push_vector));
  }
}

bool PushdownAutomaton::exec(std::string string, bool draw_trace, std::ofstream& output_file) {
  if (draw_trace) {
    output_file << "| Estado | Entrada | Pila | Acción |" << '\n';
    output_file << "|:-|:-|:-|:-|" << '\n';
  }
  char initial_symbol = stack_->initial_symbol_;
  delete stack_;
  stack_ = new Stack(initial_symbol);
  accepted_string_ = false;
  stack_->push(stack_->top());
  return recursiveExec(string, initial_state_, {}, draw_trace, output_file);
}

bool PushdownAutomaton::recursiveExec(std::string string, State* current, std::vector<char> pushing_array, bool draw_trace, std::ofstream& output_file) {
  Stack aux = *stack_;
  stack_->pop();
  for (int i = (int)pushing_array.size() - 1; i >= 0; i--) {
    if (pushing_array[i] == '.') continue;
    stack_->push(pushing_array[i]);
  }
  std::set<std::pair<State*, std::vector<char>>> symbol_transitions = current->transitionFunction(string[0], stack_->top());
  std::set<std::pair<State*, std::vector<char>>> epsilon_transitions = current->transitionFunction('.', stack_->top());
  if (draw_trace) {
    output_file << current->id_ << '|' << string + '$' << '|' << stack_->to_string() << '|';
    int i = 0;
    for (auto transition: symbol_transitions) {
      if (i == 0) output_file << "<b>";
      output_file << "[ " <<current->id_ << ' ' << string[0] << ' ' << stack_->top() << ' ' << '(' << transition.first->id_ << ' ';
      for (auto symbol: transition.second) output_file << symbol;
      output_file << ") ] " << ((i == 0)? "</b>" : "") << "; ";
      i++;
    }
    for (auto transition: epsilon_transitions) {
      if (i == 0) output_file << "<b>";
      output_file << "[ " << current->id_ << ' ' << '.' << ' ' << stack_->top() << ' ' << '(' << transition.first->id_ << ' ';
      for (auto symbol: transition.second) output_file << symbol;
      output_file << ") ] " << ((i == 0)? "</b>" : "") << "; ";
    }
    output_file << '\n';
  }
  for (auto transition: symbol_transitions) {
    accepted_string_ = recursiveExec(string.substr(1, string.size() - 1), transition.first, transition.second, draw_trace, output_file);
    if (accepted_string_) return true;
  }
  for (auto transition: epsilon_transitions) {
    accepted_string_ = recursiveExec(string, transition.first, transition.second, draw_trace, output_file);
    if (accepted_string_) return true;
  }
  if (string == "" && stack_->empty()) return true;
  *stack_ = aux;
  return accepted_string_;
}
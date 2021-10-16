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

std::set<std::string> tokenizer(std::string& s) {
    std::stringstream ss(s);
    std::string word;
    std::set<std::string> set;
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
  } while (temp_string[0] == '#');

  //Conjunto Q
  std::set<std::string> states = tokenizer(temp_string);
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
  stack_ = new Stack(temp_string);

  //Conjunto F
  std::getline(in_file, temp_string);
  std::set<std::string> tokens = tokenizer(temp_string);
  std::set<State*> final_states;
  for (auto element: tokens) {
    final_states.insert(state_map[element]);
  }
  F_ = final_states;

  //Funcion de transición
  parseTransitionFunction(in_file, state_map);
}

void PushdownAutomaton::parseAlphabet(std::ifstream& file, int option) {
  std::string temp;
  std::getline(file, temp);
  std::set<std::string> alphabet = tokenizer(temp);
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
  std::string temp, start_state, tape_symbol, pop, finish_state, push;
  std::vector<std::string> push_vector;
  while (std::getline(file, temp)) {
    std::istringstream iss(temp);
    iss >> start_state;
    iss >> tape_symbol;
    iss >> pop;
    iss >> finish_state;
    while (iss >> push) {
      push_vector.push_back(push);
    }
    state_map[start_state]->addTransition(std::make_pair(tape_symbol, pop), std::make_pair(state_map[finish_state], push_vector));
  }
}
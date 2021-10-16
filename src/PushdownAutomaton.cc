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
  stack_ = new Stack(temp_string[0]);

  //Funcion de transición
  parseTransitionFunction(in_file, state_map);
}

void PushdownAutomaton::parseAlphabet(std::ifstream& file, int option) {
  std::string temp;
  std::getline(file, temp);
  std::set<char> alphabet = tokenizerToChar(temp);
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
    iss >> pop;
    iss >> finish_state;
    push_vector.clear();
    while (iss >> push) {
      push_vector.push_back(push);
    }
    state_map[start_state]->addTransition(std::make_pair(tape_symbol, pop), std::make_pair(state_map[finish_state], push_vector));
  }
}

bool PushdownAutomaton::exec(std::string string) {
  accepted_string_ = false;
  return recursiveExec(string[0], string.substr(1, string.size() - 1), initial_state_, 0, '0');
}

bool PushdownAutomaton::recursiveExec(char tape_symbol, std::string string, State* current, int lastPushSize, char lastPop) {

}
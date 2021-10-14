#include "../include/PushdownAutomaton.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <map>
#include <vector>
#include <utility>

PushdownAutomaton::PushdownAutomaton(std::string& file_name) {
  parse(file_name);
}

std::set<std::string> tokenizer(std::string& s) {
    std::stringstream ss(s);
    std::string word;
    std::set<std::string> set;
    while (ss >> word) {
        array.push_back(word);
    }
    return set;
}

void PushdownAutomaton::parse(std::string& file_name) {
  std::ifstream in_file(file_name);
  if (in_file.fail()) {
    std::cout << "No existe el archivo.\n";
    throw -1;
  }
  std::string temp_string;
  do {
    std::getline(in_file, temp_string);
  } while (temp_string[0] == '#');

  //Conjunto Q
  std::set<std::string> states = tokenizer(temp_string);
  std::map<std::string, State*> state_map;
  for (unsigned i = 0; i < tokens.size(); i++) {
    State* new_state = new State(tokens[i]);
    state_map[tokens[i]] = new_state;
    Q_.insert(new_state);
  }

  //Alfabeto de cinta
  std::getline(in_file, temp_string);
  std::set<std::string> tape_alphabet = tokenizer(temp_string);
  tape_alphabet_ = new Alphabet(tape_alphabet);

  //Alfabeto de pila
  std::getline(in_file, temp_string);
  std::set<std::string> stack_alphabet = tokenizer(temp_string);;
  stack_alphabet_ = new Alphabet(stack_alphabet);

  //Estado inicial
  std::getline(in_file, temp_string);
  initial_state_ = state_map[temp_string];

  //Simbolo inicial de la pila
  std::getline(in_file, temp_string);
  stack_ = new Stack(temp_file);

  //Conjunto F
  std::getline(in_file, temp_string);
  tokens = tokenizer(temp_string);
  for (unsigned i = 0; i < tokens.size(); i++) {
    stack_alphabet.insert(tokens[i]);
  }


}
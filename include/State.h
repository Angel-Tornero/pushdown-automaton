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
    
    std::set<std::pair<State*,std::vector<char>>> getNext(char tape_symbol, char stack_symbol);
  
  public:
    State(std::string id);
    void addTransition(std::pair<char, char>, std::pair<State*,std::vector<char>>);
};


#endif
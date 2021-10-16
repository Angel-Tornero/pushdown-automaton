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
    std::map<std::pair<std::string, std::string>, std::set<std::pair<State*,std::vector<std::string>>>> transition_function_;
  
  public:
    State(std::string id);
    void addTransition(std::pair<std::string, std::string>, std::pair<State*,std::vector<std::string>>);
};


#endif
#include "Alphabet.h"
#include "Stack.h"
#include "State.h"
#include "TransitionFunction.h"
#include <set>
#include <map>

class PushdownAutomaton {
  private:
    Alphabet* tape_alphabet_;
    Alphabet* stack_alphabet_;
    Stack* stack_;
    TransitionFunction* transition_function_;
    std::set<State*> Q_;
    State* initial_state_;
    std::set<State*> F_;

    void parseAlphabet(std::ifstream& file, int option);
    void parseTransitionFunction(std::ifstream& file, std::map<std::string, State*>& state_map);

  public:
    PushdownAutomaton(std::string& file_name);
    void parse(std::string& file_name);
};
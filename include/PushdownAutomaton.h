#include "Alphabet.h"
#include "Stack.h"
#include "State.h"
#include "TransitionFunction.h"
#include <set>

class PushdownAutomaton {
  private:
    Alphabet* tape_alphabet_;
    Alphabet* stack_alphabet_;
    Stack* stack;
    TransitionFunction* transition_function_;
    std::set<State*> Q_;
    State* initial_state_;
    std::set<State*> F_;
    
  public:
  PushdownAutomaton(std::string& file_name);
  void parse(std::string& file_name);
};
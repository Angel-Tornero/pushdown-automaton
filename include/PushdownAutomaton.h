#include "Alphabet.h"
#include "Stack.h"
#include "State.h"
#include "Transition.h"
#include <set>
#include <map>

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

    void parseAlphabet(std::ifstream& file, int option);
    void parseTransitionFunction(std::ifstream& file, std::map<std::string, State*>& state_map);
    bool recursiveExec(char tape_symbol, std::string string, State* current, int lastPushSize, char lastPop);

  public:
    PushdownAutomaton(std::string& file_name);
    ~PushdownAutomaton();
    void parse(std::string& file_name);
    bool exec(std::string string);
};
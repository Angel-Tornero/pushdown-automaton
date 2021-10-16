#include "State.h"

/**
 * @class Transition
 * 
 */
class Transition {
  private:
    State* start_;
    State* finish_;
    char tape_symbol_;
    char stack_symbol_;
  public:
    Transition(State* start, State* finish, char tape_symbol, char stack_symbol);
};
#include "State.h"

/**
 * @class TransitionFunction
 * 
 */
class TransitionFunction {
  private:
    State* start_;
    State* finish_;
    char tape_symbol_;
    char stack_symbol_;
  public:
    TransitionFunction(State* start, State* finish, char tape_symbol, char stack_symbol);
};
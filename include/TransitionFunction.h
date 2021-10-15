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
    TransitionFunction();
};
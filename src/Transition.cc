#include "../include/Transition.h"

Transition::Transition(State* start, State* finish, char tape_symbol, char stack_symbol) {
  start_ = start;
  finish_ = finish;
  tape_symbol_ = tape_symbol;
  stack_symbol_ = stack_symbol;
}
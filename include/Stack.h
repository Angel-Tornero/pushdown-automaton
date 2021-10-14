#include <string>
#include <vector>

/**
 * @class Stack (for stack automaton)
 * 
 */
class Stack {
  private:
    std::vector<std::string> stack_;

  public:
    Stack(std::string initial_symbol);
    /**
     * @brief Get the top symbol of the stack
     * @return char
     * 
     */
    std::string top();
    /**
     * @brief Push a symbol to the stack
     * @param c char
     * 
     */
    void push(std::string c);
    /**
     * @brief Remove top element
     * 
     */
    void pop();
};
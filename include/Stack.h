#include <string>
#include <vector>

/**
 * @class Stack (for stack automaton)
 * 
 */
class Stack {
  private:
    std::vector<char> stack_;

  public:
    Stack(char initial_symbol);
    /**
     * @brief Get the top symbol of the stack
     * @return char
     * 
     */
    char top();
    /**
     * @brief Push a symbol to the stack
     * @param c char
     * 
     */
    void push(char c);
    /**
     * @brief Remove top element
     * 
     */
    void pop();
    /**
     * @brief Checks if the stack is empty
     * 
     * @return true 
     * @return false 
     */
    bool empty();

    std::ostream& operator<<(std::ostream& os);
};
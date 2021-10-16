#include <string>
#include <set>

/**
 * @class Alphabet
 * 
 */
class Alphabet {
  private:
    friend class PushdownAutomaton;
    std::set<char> symbols_;
  
  public:
    Alphabet(std::set<char> symbols);
    /**
     * @brief Check if the alphabet contains the given character
     * @param c char
     * @returns bool
     * 
     */
    bool contain(char c);

    std::ostream& operator<<(std::ostream&);
};
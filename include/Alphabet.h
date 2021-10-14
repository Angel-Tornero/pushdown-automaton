#include <string>
#include <set>

/**
 * @class Alphabet
 * 
 */
class Alphabet {
  private:
    std::set<std::string> symbols_;
  
  public:
    Alphabet(std::set<std::string> symbols);
    /**
     * @brief Check if the alphabet contains the given character
     * @param c char
     * @returns bool
     * 
     */
    bool contain(std::string c);
};
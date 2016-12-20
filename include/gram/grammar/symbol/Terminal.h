#ifndef GRAM_GRAMMAR_SYMBOL_TERMINAL
#define GRAM_GRAMMAR_SYMBOL_TERMINAL

#include <string>

namespace gram {
namespace grammar {
/**
 * Class.
 */
class Terminal {
 public:
  Terminal(std::string value);
  std::string value();
  bool operator==(const Terminal &terminal) const;
  bool operator!=(const Terminal &terminal) const;
 private:
  std::string val;
};
}
}

#endif // GRAM_GRAMMAR_SYMBOL_TERMINAL

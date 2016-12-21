#ifndef GRAM_GRAMMAR_SYMBOL_NON_TERMINAL
#define GRAM_GRAMMAR_SYMBOL_NON_TERMINAL

#include <memory>
#include <vector>

#include <gram/grammar/symbol/Option.h>

namespace gram {
namespace grammar {
// Forward declaration.
class Option;
/**
 * Class.
 */
class NonTerminal {
 public:
  void addOption(std::weak_ptr<Option> option);
  std::shared_ptr<Option> optionAt(unsigned long index);
  unsigned long size() const;
  bool operator==(const NonTerminal &nonTerminal) const;
  bool operator!=(const NonTerminal &nonTerminal) const;
 private:
  std::vector<std::weak_ptr<Option>> options;
};
}
}

#endif // GRAM_GRAMMAR_SYMBOL_NON_TERMINAL

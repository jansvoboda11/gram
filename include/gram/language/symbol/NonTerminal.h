#ifndef GRAM_LANGUAGE_NON_TERMINAL_SYMBOL
#define GRAM_LANGUAGE_NON_TERMINAL_SYMBOL

#include <memory>
#include <vector>

#include <gram/language/symbol/Option.h>

namespace gram {
// Forward declaration.
class Option;
/**
 * Class.
 */
class NonTerminal {
 public:
  void addOption(std::shared_ptr<Option> option);
  std::shared_ptr<Option> optionAt(unsigned long index);
  unsigned long size() const;
  bool operator==(const NonTerminal &nonTerminal) const;
  bool operator!=(const NonTerminal &nonTerminal) const;
 private:
  std::vector<std::shared_ptr<Option>> options;
};
}

#endif // GRAM_LANGUAGE_NON_TERMINAL_SYMBOL

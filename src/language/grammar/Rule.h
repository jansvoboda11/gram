#ifndef GRAM_LANGUAGE_GRAMMAR_RULE
#define GRAM_LANGUAGE_GRAMMAR_RULE

#include <unordered_map>

#include <language/grammar/symbol/NonTerminal.h>
#include <language/grammar/symbol/Terminal.h>

namespace gram {
namespace language {
namespace grammar {
// Forward declaration.
class NonTerminal;
/**
 * Class.
 */
class Rule {
 public:
  Rule();
  void addNonTerminal(NonTerminal &nonTerminal);
  void addTerminal(Terminal &terminal);
  bool hasNonTerminalAt(int index);
  bool hasTerminalAt(int index);
  NonTerminal &nonTerminalAt(int index);
  Terminal &terminalAt(int index);
  int size();
  bool operator==(const Rule &rule) const;
  bool operator!=(const Rule &rule) const;
 private:
  std::unordered_map<int, NonTerminal *> nonTerminals;
  std::unordered_map<int, Terminal *> terminals;
  int symbolCount;
};
}
}
}

#endif // GRAM_LANGUAGE_GRAMMAR_RULE

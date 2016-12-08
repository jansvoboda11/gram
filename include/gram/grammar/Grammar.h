#ifndef GRAM_GRAMMAR_GRAMMAR
#define GRAM_GRAMMAR_GRAMMAR

#include <gram/grammar/symbol/Option.h>

namespace gram {
namespace grammar {
/**
 * Class.
 */
class Grammar {
 public:
  Grammar(std::shared_ptr<NonTerminal> startSymbol);
  std::shared_ptr<NonTerminal> getStartSymbol();
 private:
  std::weak_ptr<NonTerminal> startSymbol;
};
}
}

#endif // GRAM_GRAMMAR_GRAMMAR

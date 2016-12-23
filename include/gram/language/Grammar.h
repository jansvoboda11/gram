#ifndef GRAM_LANGUAGE_GRAMMAR
#define GRAM_LANGUAGE_GRAMMAR

#include <gram/language/symbol/Option.h>

namespace gram {
namespace language {
/**
 * Class.
 */
class Grammar {
 public:
  Grammar(std::shared_ptr<NonTerminal> startSymbol);
  virtual ~Grammar() = default;
  virtual std::shared_ptr<NonTerminal> startSymbol() const;
 private:
  std::shared_ptr<NonTerminal> start;
};
}
}

#endif // GRAM_LANGUAGE_GRAMMAR

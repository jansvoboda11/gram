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
  Grammar(std::shared_ptr<NonTerminal> startSymbol, std::unordered_map<std::string, std::shared_ptr<NonTerminal>> rules);
  virtual ~Grammar() = default;
  virtual std::shared_ptr<NonTerminal> startSymbol() const;
 private:
  std::shared_ptr<NonTerminal> start;
  std::unordered_map<std::string, std::shared_ptr<NonTerminal>> rules;
};
}
}

#endif // GRAM_LANGUAGE_GRAMMAR

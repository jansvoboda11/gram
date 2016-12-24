#include <gram/language/Grammar.h>

using namespace gram::language;

Grammar::Grammar(std::shared_ptr<NonTerminal> startSymbol, std::unordered_map<std::string, std::shared_ptr<NonTerminal>> rules)
    : start(startSymbol), rules(rules) {
  //
}

std::shared_ptr<NonTerminal> Grammar::startSymbol() const {
  if (!start) {
    throw std::logic_error("The start symbol of grammar is invalid.");
  }

  return start;
}

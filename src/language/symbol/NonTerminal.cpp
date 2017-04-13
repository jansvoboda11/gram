#include <gram/language/symbol/NonTerminal.h>

#include <gram/language/symbol/Rule.h>

using namespace gram;
using namespace std;

NonTerminal::NonTerminal(std::weak_ptr<Rule> rule) : rule(rule) {
  //
}

Rule& NonTerminal::toRule() const {
  return *rule.lock();
}

bool NonTerminal::isTerminal() const {
  return false;
}

bool NonTerminal::isNonTerminal() const {
  return true;
}

bool NonTerminal::operator==(const NonTerminal& nonTerminal) const {
  return *rule.lock() == *nonTerminal.rule.lock();
}

bool NonTerminal::operator!=(const NonTerminal& nonTerminal) const {
  return !operator==(nonTerminal);
}

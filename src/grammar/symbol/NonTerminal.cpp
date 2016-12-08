#include <gram/grammar/symbol/NonTerminal.h>

using namespace gram::grammar;

void NonTerminal::addRule(std::weak_ptr<Rule> rule) {
  rules.push_back(rule);
}

std::shared_ptr<Rule> NonTerminal::ruleAt(unsigned long index) {
  return rules[index].lock();
}

unsigned long NonTerminal::ruleCount() {
  return rules.size();
}

bool NonTerminal::operator==(const NonTerminal &nonTerminal) const {
  if (rules.size() != nonTerminal.rules.size()) {
    return false;
  }

  size_t size = rules.size();

  for (int i = 0; i < size; i++) {
    std::shared_ptr<Rule> firstRule = rules[i].lock();
    std::shared_ptr<Rule> secondRule = nonTerminal.rules[i].lock();

    if (*firstRule != *secondRule) {
      return false;
    }
  }

  return true;
}

bool NonTerminal::operator!=(const NonTerminal &nonTerminal) const {
  return !operator==(nonTerminal);
}

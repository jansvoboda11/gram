#include <language/grammar/symbol/NonTerminal.h>

using namespace gram::language::grammar;

void NonTerminal::addRule(Rule &rule) {
  rules.push_back(&rule);
}

Rule &NonTerminal::ruleAt(int index) {
  return *rules[index];
}

bool NonTerminal::operator==(const NonTerminal &nonTerminal) const {
  if (rules.size() != nonTerminal.rules.size()) {
    return false;
  }

  size_t size = rules.size();

  for (int i = 0; i < size; i++) {
    Rule firstRule = *rules[i];
    Rule secondRule = *nonTerminal.rules[i];

    if (firstRule != secondRule) {
      return false;
    }
  }

  return true;
}

bool NonTerminal::operator!=(const NonTerminal &nonTerminal) const {
  return !operator==(nonTerminal);
}

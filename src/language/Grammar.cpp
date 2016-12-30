#include <gram/language/Grammar.h>

using namespace gram;
using namespace std;

Grammar::Grammar() : start(), rules() {
  //
}

void Grammar::addRule(string name, shared_ptr<NonTerminal> rule) {
  rules[name] = rule;

  if (!start) {
    start = rule;
  }
}

shared_ptr<NonTerminal> Grammar::ruleNamed(string name) {
  shared_ptr<NonTerminal> &rule = rules[name];

  if (!rule) {
    rule = make_shared<NonTerminal>();
  }

  if (!start) {
    start = rule;
  }

  return rule;
}

shared_ptr<NonTerminal> Grammar::startRule() const {
  if (!start) {
    throw logic_error("The start symbol of grammar is invalid.");
  }

  return start;
}

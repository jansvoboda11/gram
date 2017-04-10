#include <gram/language/grammar/ContextFreeGrammar.h>

using namespace gram;
using namespace std;

ContextFreeGrammar::ContextFreeGrammar() : start(), rules() {
  //
}

void ContextFreeGrammar::addRule(string name, shared_ptr<NonTerminal> rule) {
  rules[name] = rule;

  if (!start) {
    start = rule;
  }
}

shared_ptr<NonTerminal> ContextFreeGrammar::ruleNamed(string name) {
  shared_ptr<NonTerminal>& rule = rules[name];

  if (!rule) {
    rule = make_shared<NonTerminal>();
  }

  if (!start) {
    start = rule;
  }

  return rule;
}

shared_ptr<NonTerminal> ContextFreeGrammar::startRule() const {
  if (!start) {
    throw logic_error("The start symbol of grammar is invalid.");
  }

  return start;
}

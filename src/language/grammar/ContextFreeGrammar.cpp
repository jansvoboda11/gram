#include <gram/language/grammar/ContextFreeGrammar.h>

using namespace gram;
using namespace std;

ContextFreeGrammar::ContextFreeGrammar() : start(), rules() {
  //
}

void ContextFreeGrammar::addRule(shared_ptr<Rule> rule) {
  rules[rule->getName()] = rule;

  if (!start) {
    start = rule;
  }
}

shared_ptr<Rule> ContextFreeGrammar::ruleNamed(string name) {
  shared_ptr<Rule>& rule = rules[name];

  if (!rule) {
    rule = make_shared<Rule>(name);
  }

  if (!start) {
    start = rule;
  }

  return rule;
}

shared_ptr<Rule> ContextFreeGrammar::startRule() const {
  if (!start) {
    throw logic_error("The start symbol of grammar is invalid.");
  }

  return start;
}

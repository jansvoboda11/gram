#include <gram/language/Grammar.h>

using namespace gram;
using namespace std;

Grammar::Grammar() : start(), rules() {
  //
}

void Grammar::addRule(string name, shared_ptr<NonTerminal> rule) {
  if (!start) {
    start = rule;
  }

  rules[name] = rule;
}

bool Grammar::hasRuleNamed(string name) const {
  auto found = rules.find(name);

  return found != rules.end();
}

shared_ptr<NonTerminal> Grammar::ruleNamed(string name) {
  if (!hasRuleNamed(name)) {
    auto rule = make_shared<NonTerminal>();

    addRule(name, rule);
  }

  return rules[name];
}

shared_ptr<NonTerminal> Grammar::startRule() const {
  if (!start) {
    throw logic_error("The start symbol of grammar is invalid.");
  }

  return start;
}

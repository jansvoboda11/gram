#include <gram/language/grammar/ContextFreeGrammar.h>

using namespace gram;
using namespace std;

ContextFreeGrammar::ContextFreeGrammar() : start("") {
  //
}

void ContextFreeGrammar::addRule(unique_ptr<Rule> rule) {
  if (start.length() == 0) {
    start = rule->getName();
  }

  rules[rule->getName()] = move(rule);
}

Rule& ContextFreeGrammar::ruleNamed(string name) {
  Rule* rule = rules[name].get();

  if (!rule) {
    auto newRule = make_unique<Rule>(name);

    rule = newRule.get();

    rules[name] = move(newRule);
  }

  if (start.length() == 0) {
    start = rule->getName();
  }

  return *rule;
}

Rule& ContextFreeGrammar::startRule() {
  if (start.length() == 0) {
    throw logic_error("The grammar does not contain any rules.");
  }

  return *rules[start].get();
}

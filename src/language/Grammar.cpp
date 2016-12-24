#include <gram/language/Grammar.h>

using namespace gram::language;

Grammar::Grammar() : start(), rules() {
  //
}

void Grammar::addRule(std::string name, std::shared_ptr<NonTerminal> rule) {
  if (!start) {
    start = rule;
  }

  rules[name] = rule;
}

bool Grammar::hasRuleNamed(std::string name) {
  auto found = rules.find(name);

  return found != rules.end();
}

std::shared_ptr<NonTerminal> Grammar::ruleNamed(std::string name) {
  if (!hasRuleNamed(name)) {
    auto rule = std::make_shared<NonTerminal>();

    addRule(name, rule);
  }

  return rules[name];
}

std::shared_ptr<NonTerminal> Grammar::startRule() {
  if (!start) {
    throw std::logic_error("The start symbol of grammar is invalid.");
  }

  return start;
}

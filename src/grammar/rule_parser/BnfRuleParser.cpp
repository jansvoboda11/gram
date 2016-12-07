#include <gram/grammar/rule_parser/BnfRuleParser.h>

using namespace gram::grammar;

BnfRuleParser::BnfRuleParser(std::string rules) : input(rules) {
  //
}

Grammar BnfRuleParser::parse() {
  std::weak_ptr<Rule> rule;

  return Grammar(rule);
}

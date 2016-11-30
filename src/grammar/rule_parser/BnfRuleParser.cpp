#include <gram/grammar/rule_parser/BnfRuleParser.h>

using namespace gram::grammar;

BnfRuleParser::BnfRuleParser(std::string rules) : input(rules) {
  //
}

Grammar BnfRuleParser::parse() {
  Rule rule;

  return Grammar(rule);
}

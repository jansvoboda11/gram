#include "BnfRuleParser.h"

using namespace gram::language::grammar;

BnfRuleParser::BnfRuleParser(std::string rules) : input(rules) {
  //
}

Grammar BnfRuleParser::parse() {
  return Grammar();
}

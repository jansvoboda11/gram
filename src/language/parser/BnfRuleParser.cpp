#include <gram/language/parser/BnfRuleParser.h>

using namespace gram::language;

Grammar BnfRuleParser::parse(std::string rules) {
  std::smatch matches;

  std::regex nonTerm(nonTerminal());
  std::string name;

  if (std::regex_search(rules, matches, nonTerm)) {
    name = matches[1];
  }

  std::regex eq(equals());

  if (!std::regex_search(rules, matches, eq)) {
    throw std::logic_error("Rule does not contain equals.");
  }

  std::regex term(terminal());
  std::string value;

  if (std::regex_search(rules, matches, term)) {
    value = matches[1];
  }

  Terminal terminal1(value);

  auto option = std::make_shared<Option>();
  option->addTerminal(terminal1);

  auto startSymbol = std::make_shared<NonTerminal>();
  startSymbol->addOption(option);

  return Grammar(startSymbol);
}

std::string BnfRuleParser::nonTerminal() {
  return std::string(" *<([a-zA-Z][a-zA-Z0-9-]*)> *");
}

std::string BnfRuleParser::equals() {
  return std::string(" *::= *");
}

std::string BnfRuleParser::terminal() {
  return std::string(" *\"([a-zA-Z0-9| -!#$%&\\(\\)\\*\\+,-\\./:;<=>?@\\[\\\\\\]\\^_`{}~]+)\" *");
}

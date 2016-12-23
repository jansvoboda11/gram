#include <gram/language/parser/BnfRuleParser.h>

using namespace gram::language;

Grammar BnfRuleParser::parse(std::string rules) {
  std::smatch matches;

  std::string nonTermi = nonTerminal();
  std::regex nonTerm(nonTermi);
  std::string name;

  if (std::regex_search(rules, matches, nonTerm)) {
    name = matches[1];
  }

  rules = rules.substr(name.length() + 2);

  std::string equ = equals();
  std::regex eq(equ);

  if (!std::regex_search(rules, matches, eq)) {
    throw std::logic_error("Rule does not contain equals.");
  }

  rules = rules.substr(4);

  std::string termi = terminal();
  std::regex term(termi);

  auto option = std::make_shared<Option>();

  while (rules.length() > 0) {
    std::string value;

    if (std::regex_search(rules, matches, term)) {
      value = matches[1];
    }

    rules = rules.substr(value.length() + 3);

    Terminal terminal1(value);
    option->addTerminal(terminal1);
  }

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

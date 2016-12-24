#include <gram/language/parser/BnfRuleParser.h>

using namespace gram::language;

Grammar BnfRuleParser::parse(std::string rules) {
  Grammar grammar;

  std::vector<std::string> lines = explode(rules, "\n");

  std::string nonTermi = "^" + nonTerminal();
  std::regex nonTerm(nonTermi);
  std::string name;
  std::smatch matches;
  if (std::regex_search(rules, matches, nonTerm)) {
    name = matches[1];
  }

  auto nonT = std::make_shared<NonTerminal>();

  grammar.addRule(name, nonT);

  for (auto &rule : lines) {
    if (std::regex_search(rule, matches, nonTerm)) {
      name = matches[1];
    }

    if (grammar.hasRuleNamed(name)) {
      nonT = grammar.ruleNamed(name);
    } else {
      nonT = std::make_shared<NonTerminal>();
      grammar.addRule(name, nonT);
    }

    rule = rule.substr(name.length() + 2);

    std::string equ = "^" + equals();
    std::regex eq(equ);

    if (!std::regex_search(rule, matches, eq)) {
      throw std::logic_error("Rule does not contain equals.");
    }

    rule = rule.substr(4);

    std::string termi = "^" + terminal();
    std::regex term(termi);

    std::string pi = "^" + pipe();
    std::regex pip(pi);

    auto option = std::make_shared<Option>();
    nonT->addOption(option);

    while (rule.length() > 0) {
      std::string value;

      if (std::regex_search(rule, matches, term)) {
        value = matches[1];

        unsigned long offset = std::min(value.length() + 3, rule.length());

        rule = rule.substr(offset);

        Terminal terminal1(value);
        option->addTerminal(terminal1);
      } else if (std::regex_search(rule, matches, pip)) {
        rule = rule.substr(2);

        option = std::make_shared<Option>();
        nonT->addOption(option);
      } else if (std::regex_search(rule, matches, nonTerm)) {
        name = matches[1];

        rule = rule.substr(name.length() + 3);

        std::shared_ptr<NonTerminal> encountered;

        if (grammar.hasRuleNamed(name)) {
          encountered = grammar.ruleNamed(name);
        } else {
          encountered = std::make_shared<NonTerminal>();
          grammar.addRule(name, encountered);
        }

        option->addNonTerminal(encountered);
      }
    }
  }

  return grammar;
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

std::string BnfRuleParser::pipe() {
  return std::string(" *\\| *");
}

std::vector<std::string> BnfRuleParser::explode(std::string string, std::string delimiter) {
  std::vector<std::string> pieces;

  unsigned long end = string.find(delimiter);

  while (end != std::string::npos) {
    pieces.push_back(string.substr(0, end));

    string = string.substr(end + delimiter.length());

    end = string.find(delimiter);
  }

  pieces.push_back(string);

  return pieces;
}

#include <gram/language/parser/BnfRuleParser.h>

using namespace gram::language;

Grammar BnfRuleParser::parse(std::string input) {
  Grammar grammar;

  std::vector<std::string> lines = explode(input, "\n");

  for (auto line : lines) {
    parseRule(grammar, line);
  }

  return grammar;
}

void BnfRuleParser::parseRule(Grammar &grammar, std::string &line) {
  std::regex nonTerminalPattern(nonTerminal());
  std::regex equalsPattern(equals());
  std::smatch matches;
  std::string name;

  if (std::regex_search(line, matches, nonTerminalPattern)) {
    name = matches[1];
  }

  std::shared_ptr<NonTerminal> rule = grammar.ruleNamed(name);

  line = line.substr(name.length() + 2);

  if (!std::regex_search(line, matches, equalsPattern)) {
    throw std::logic_error("Rule start could not be parsed.");
  }

  line = line.substr(4);

  while (line.length() > 0) {
    std::shared_ptr<Option> option = parseOption(grammar, line);

    rule->addOption(option);
  }
}

std::shared_ptr<Option> BnfRuleParser::parseOption(Grammar &grammar, std::string &line) {
  auto option = std::make_shared<Option>();

  std::regex terminalPattern(terminal());
  std::regex nonTerminalPattern(nonTerminal());
  std::regex delimiterPattern(pipe());
  std::smatch matches;

  while (line.length() > 0) {
    if (std::regex_search(line, matches, terminalPattern)) {
      std::string value = matches[1];

      Terminal term(value);
      option->addTerminal(term);

      line = line.substr(std::min(value.length() + 3, line.length()));
    } else if (std::regex_search(line, matches, nonTerminalPattern)) {
      std::string name = matches[1];

      std::shared_ptr<NonTerminal> nonTerm = grammar.ruleNamed(name);
      option->addNonTerminal(nonTerm);

      line = line.substr(name.length() + 3);
    } else if (std::regex_search(line, matches, delimiterPattern)) {
      line = line.substr(2);

      break;
    } else {
      throw std::logic_error("Rule option could not be parsed.");
    }
  }

  return option;
}

std::string BnfRuleParser::nonTerminal() {
  return std::string("^ *<([a-zA-Z][a-zA-Z0-9-]*)> *");
}

std::string BnfRuleParser::equals() {
  return std::string("^ *::= *");
}

std::string BnfRuleParser::terminal() {
  return std::string("^ *\"([a-zA-Z0-9| -!#$%&\\(\\)\\*\\+,-\\./:;<=>?@\\[\\\\\\]\\^_`{}~]+)\" *");
}

std::string BnfRuleParser::pipe() {
  return std::string("^ *\\| *");
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

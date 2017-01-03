#include <gram/language/parser/BnfRuleParser.h>

#include <gram/util/helper.h>

using namespace gram;
using namespace std;

ContextFreeGrammar BnfRuleParser::parse(string input) const {
  ContextFreeGrammar grammar;

  vector<string> lines = explode(input, "\n");

  for (auto line : lines) {
    parseRule(grammar, line);
  }

  return grammar;
}

void BnfRuleParser::parseRule(ContextFreeGrammar& grammar, string& line) const {
  string name;

  line = left_trim(line);

  if (line.empty()) {
    return;
  }

  if (!parseNonTerminal(name, line) || !parseEquals(line)) {
    throw logic_error("The BNF grammar could not be parsed.");
  }

  shared_ptr<NonTerminal> rule = grammar.ruleNamed(name);

  while (line.length() > 0) {
    Option option = parseOption(grammar, line);
    rule->addOption(make_shared<Option>(option));
  }
}

Option BnfRuleParser::parseOption(ContextFreeGrammar& grammar, string& line) const {
  Option option;

  while (line.length() > 0) {
    string name;
    string value;

    if (parseNonTerminal(name, line)) {
      shared_ptr<NonTerminal> nonTerminal = grammar.ruleNamed(name);
      option.addNonTerminal(nonTerminal);
    } else if (parseTerminal(value, line)) {
      Terminal terminal(value);
      option.addTerminal(terminal);
    } else if (parsePipe(line)) {
      break;
    } else {
      throw logic_error("The BNF grammar could not be parsed.");
    }
  }

  return option;
}

bool BnfRuleParser::parseNonTerminal(string& name, string& line) const {
  regex pattern("^<([a-zA-Z][a-zA-Z0-9-]*)>");
  smatch matches;

  if (!regex_search(line, matches, pattern)) {
    return false;
  }

  name = matches[1];
  line = line.substr(name.length() + 2);
  line = left_trim(line);

  return true;
}

bool BnfRuleParser::parseTerminal(string& value, string& line) const {
  regex pattern("^\"([a-zA-Z0-9| -!#$%&\\(\\)\\*\\+,-\\./:;<=>?@\\[\\\\\\]\\^_`{}~]+)\"");
  smatch matches;

  if (!regex_search(line, matches, pattern)) {
    return false;
  }

  value = matches[1];
  line = line.substr(value.length() + 2);
  line = left_trim(line);

  return true;
}

bool BnfRuleParser::parseEquals(string& line) const {
  regex pattern("^::=");
  smatch matches;

  if (!regex_search(line, matches, pattern)) {
    return false;
  }

  line = line.substr(3);
  line = left_trim(line);

  return true;
}

bool BnfRuleParser::parsePipe(string& line) const {
  regex pattern("^\\|");
  smatch matches;

  if (!regex_search(line, matches, pattern)) {
    return false;
  }

  line = line.substr(1);
  line = left_trim(line);

  return true;
}

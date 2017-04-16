#include <gram/language/parser/BnfRuleParser.h>

#include <gram/error/InvalidGrammar.h>
#include <gram/util/helper.h>

using namespace gram;
using namespace std;

ContextFreeGrammar BnfRuleParser::parse(string input) const {
  // todo: handle multi-line rules

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
    throw InvalidGrammar();
  }

  Rule& rule = grammar.ruleNamed(name);

  while (line.length() > 0) {
    unique_ptr<Option> option = parseOption(grammar, line);
    rule.addOption(move(option));
  }
}

unique_ptr<Option> BnfRuleParser::parseOption(ContextFreeGrammar& grammar, string& line) const {
  auto option = make_unique<Option>();

  while (line.length() > 0) {
    string name;
    string value;

    if (parseNonTerminal(name, line)) {
      Rule& rule = grammar.ruleNamed(name);
      auto nonTerminal = make_unique<NonTerminal>(rule);
      option->addNonTerminal(move(nonTerminal));
    } else if (parseTerminal(value, line)) {
      auto terminal = make_unique<Terminal>(value);
      option->addTerminal(move(terminal));
    } else if (parsePipe(line)) {
      break;
    } else {
      throw InvalidGrammar();
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

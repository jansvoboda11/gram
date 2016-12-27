#include <gram/language/parser/BnfRuleParser.h>

#include <gram/util/helper.h>

using namespace gram;
using namespace std;

Grammar BnfRuleParser::parse(string input) const {
  Grammar grammar;

  vector<string> lines = explode(input, "\n");

  for (auto line : lines) {
    parseRule(grammar, line);
  }

  return grammar;
}

void BnfRuleParser::parseRule(Grammar& grammar, string& line) const {
  regex nonTerminalPattern(nonTerminal());
  regex equalsPattern(equals());
  smatch matches;
  string name;

  if (regex_search(line, matches, nonTerminalPattern)) {
    name = matches[1];
  }

  shared_ptr<NonTerminal> rule = grammar.ruleNamed(name);

  // todo: improve whitespace handling
  line = line.substr(name.length() + 2);

  if (!regex_search(line, matches, equalsPattern)) {
    throw logic_error("Rule start could not be parsed.");
  }

  line = line.substr(4);

  while (line.length() > 0) {
    Option option = parseOption(grammar, line);

    rule->addOption(make_shared<Option>(option));
  }
}

Option BnfRuleParser::parseOption(Grammar& grammar, string& line) const {
  Option option;

  regex terminalPattern(terminal());
  regex nonTerminalPattern(nonTerminal());
  regex delimiterPattern(pipe());
  smatch matches;

  while (line.length() > 0) {
    if (regex_search(line, matches, terminalPattern)) {
      string value = matches[1];

      Terminal term(value);
      option.addTerminal(term);

      line = line.substr(min(value.length() + 3, line.length()));
    } else if (regex_search(line, matches, nonTerminalPattern)) {
      string name = matches[1];

      shared_ptr<NonTerminal> nonTerm = grammar.ruleNamed(name);
      option.addNonTerminal(nonTerm);

      line = line.substr(name.length() + 3);
    } else if (regex_search(line, matches, delimiterPattern)) {
      line = line.substr(2);

      break;
    } else {
      throw logic_error("Rule option could not be parsed.");
    }
  }

  return option;
}

string BnfRuleParser::nonTerminal() const {
  return string("^ *<([a-zA-Z][a-zA-Z0-9-]*)> *");
}

string BnfRuleParser::equals() const {
  return string("^ *::= *");
}

string BnfRuleParser::terminal() const {
  return string("^ *\"([a-zA-Z0-9| -!#$%&\\(\\)\\*\\+,-\\./:;<=>?@\\[\\\\\\]\\^_`{}~]+)\" *");
}

string BnfRuleParser::pipe() const {
  return string("^ *\\| *");
}

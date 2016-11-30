#include <gram/language/grammar/Grammar.h>

using namespace gram::language::grammar;

Grammar::Grammar(Rule startRule) : startRule(startRule) {
  //
}

Rule Grammar::getStartRule() {
  return startRule;
}

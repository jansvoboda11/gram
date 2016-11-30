#include <gram/grammar/Grammar.h>

using namespace gram::grammar;

Grammar::Grammar(Rule startRule) : startRule(startRule) {
  //
}

Rule Grammar::getStartRule() {
  return startRule;
}

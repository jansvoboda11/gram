#include <gram/grammar/Grammar.h>

using namespace gram::grammar;

Grammar::Grammar(std::weak_ptr<Rule> startRule) : startRule(startRule) {
  //
}

std::shared_ptr<Rule> Grammar::getStartRule() {
  return startRule.lock();
}

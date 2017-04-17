#ifndef GRAM_LANGUAGE_CONTEXT_FREE_GRAMMAR
#define GRAM_LANGUAGE_CONTEXT_FREE_GRAMMAR

#include <memory>
#include <string>
#include <unordered_map>

#include "gram/language/symbol/Rule.h"

namespace gram {
/**
 * Class.
 */
class Rule;

class ContextFreeGrammar {
 public:
  ContextFreeGrammar();
  void addRule(std::unique_ptr<Rule> rule);
  Rule& ruleNamed(std::string name);
  Rule& startRule();
 private:
  std::string start;
  std::unordered_map<std::string, std::unique_ptr<Rule>> rules;
};
}

#endif // GRAM_LANGUAGE_CONTEXT_FREE_GRAMMAR

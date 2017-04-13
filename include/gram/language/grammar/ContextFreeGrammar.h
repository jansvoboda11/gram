#ifndef GRAM_LANGUAGE_CONTEXT_FREE_GRAMMAR
#define GRAM_LANGUAGE_CONTEXT_FREE_GRAMMAR

#include <memory>
#include <unordered_map>

#include <gram/language/symbol/Rule.h>

namespace gram {
/**
 * Class.
 */
class ContextFreeGrammar {
 public:
  ContextFreeGrammar();
  void addRule(std::shared_ptr<Rule> rule);
  std::shared_ptr<Rule> ruleNamed(std::string name);
  std::shared_ptr<Rule> startRule() const;
 private:
  std::shared_ptr<Rule> start;
  std::unordered_map<std::string, std::shared_ptr<Rule>> rules;
};
}

#endif // GRAM_LANGUAGE_CONTEXT_FREE_GRAMMAR

#ifndef GRAM_LANGUAGE_GRAMMAR
#define GRAM_LANGUAGE_GRAMMAR

#include <gram/language/symbol/Option.h>

namespace gram {
namespace language {
/**
 * Class.
 */
class Grammar {
 public:
  Grammar();
  virtual ~Grammar() = default;
  void addRule(std::string name, std::shared_ptr<NonTerminal> rule);
  bool hasRuleNamed(std::string name);
  std::shared_ptr<NonTerminal> ruleNamed(std::string name);
  virtual std::shared_ptr<NonTerminal> startRule();
 private:
  std::shared_ptr<NonTerminal> start;
  std::unordered_map<std::string, std::shared_ptr<NonTerminal>> rules;
};
}
}

#endif // GRAM_LANGUAGE_GRAMMAR

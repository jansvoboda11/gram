#ifndef GRAM_LANGUAGE_RULE
#define GRAM_LANGUAGE_RULE

#include <memory>
#include <string>
#include <vector>

#include "gram/language/symbol/Option.h"

namespace gram {
/**
 * Class.
 */
class Rule {
 public:
  Rule(std::string name);
  std::string getName() const;
  void addOption(std::unique_ptr<gram::Option> option);
  Option& operator[](unsigned long index) const;
  unsigned long size() const;
  bool operator==(const Rule& rule) const;
  bool operator!=(const Rule& rule) const;
 private:
  std::string name;
  std::vector<std::unique_ptr<Option>> options;
};
}

#endif // GRAM_LANGUAGE_RULE

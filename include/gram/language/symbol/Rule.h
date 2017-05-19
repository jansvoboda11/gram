#ifndef GRAM_RULE
#define GRAM_RULE

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

private:
  std::string name;
  std::vector<std::unique_ptr<Option>> options;
};
}

#endif

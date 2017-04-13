#ifndef GRAM_INDIVIDUAL_PHENOTYPE
#define GRAM_INDIVIDUAL_PHENOTYPE

#include <memory>
#include <string>
#include <vector>

#include <gram/language/symbol/Terminal.h>

namespace gram {
/**
 * Class.
 */
class Phenotype {
 public:
  void addTerminal(std::shared_ptr<Terminal> terminal);
  virtual std::string serialize() const;
  bool operator==(const Phenotype& phenotype) const;
  bool operator!=(const Phenotype& phenotype) const;
 private:
  std::vector<std::shared_ptr<Terminal>> terminals;
};
}

#endif // GRAM_INDIVIDUAL_PHENOTYPE

#ifndef GRAM_INDIVIDUAL_PHENOTYPE
#define GRAM_INDIVIDUAL_PHENOTYPE

#include <string>
#include <vector>

#include <gram/language/symbol/Terminal.h>

namespace gram {
namespace individual {
/**
 * Class.
 */
class Phenotype {
 public:
  void addTerminal(gram::language::Terminal terminal);
  virtual std::string serialize();
  bool operator==(const Phenotype &phenotype) const;
  bool operator!=(const Phenotype &phenotype) const;
 private:
  std::vector<gram::language::Terminal> terminals;
};
}
}

#endif // GRAM_INDIVIDUAL_PHENOTYPE

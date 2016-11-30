#ifndef GRAM_INDIVIDUAL_PHENOTYPE
#define GRAM_INDIVIDUAL_PHENOTYPE

#include <string>
#include <vector>

#include <gram/grammar/symbol/Terminal.h>

namespace gram {
namespace individual {
/**
 * Class.
 */
class Phenotype {
 public:
  void addTerminal(gram::grammar::Terminal terminal);
  gram::grammar::Terminal terminalAt(int index);
  std::string serialize();
  bool operator==(const Phenotype &phenotype) const;
  bool operator!=(const Phenotype &phenotype) const;
 private:
  std::vector<gram::grammar::Terminal> terminals;
};
}
}

#endif // GRAM_INDIVIDUAL_PHENOTYPE

#ifndef GRAM_INDIVIDUAL_PHENOTYPE
#define GRAM_INDIVIDUAL_PHENOTYPE

#include <string>
#include <vector>

#include "../../language/grammar/symbol/Terminal.h"

namespace gram {
namespace population {
namespace individual {
/**
 * Class.
 */
class Phenotype {
 public:
  void addTerminal(gram::language::grammar::Terminal terminal);
  gram::language::grammar::Terminal terminalAt(int index);
  std::string serialize();
  bool operator==(const Phenotype &phenotype) const;
  bool operator!=(const Phenotype &phenotype) const;
 private:
  std::vector<gram::language::grammar::Terminal> terminals;
};
}
}
}

#endif // GRAM_INDIVIDUAL_PHENOTYPE

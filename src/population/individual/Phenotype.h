#ifndef GRAM_INDIVIDUAL_PHENOTYPE
#define GRAM_INDIVIDUAL_PHENOTYPE

#include <string>
#include <vector>
#include "../../language/grammar/symbol/TerminalSymbol.h"

namespace gram {
namespace population {
namespace individual {
/**
 * Class.
 */
class Phenotype {
 public:
  Phenotype(std::vector<gram::language::grammar::TerminalSymbol> terminals);
  std::string serialize();
 private:
  std::vector<gram::language::grammar::TerminalSymbol> terminals;
};
}
}
}

#endif // GRAM_INDIVIDUAL_PHENOTYPE

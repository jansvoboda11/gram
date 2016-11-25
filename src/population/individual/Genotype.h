#ifndef GRAM_INDIVIDUAL_GENOTYPE
#define GRAM_INDIVIDUAL_GENOTYPE

#include <vector>

namespace gram {
namespace population {
namespace individual {
/**
 * Class.
 */
struct Genotype {
 public:
  Genotype(std::vector<int> values);
  std::vector<int> genes();
  unsigned long size();
  int &operator[](int index);
  bool operator==(const Genotype &genotype) const;
  bool operator!=(const Genotype &genotype) const;
 private:
  std::vector<int> values;
};
}
}
}

#endif // GRAM_INDIVIDUAL_GENOTYPE

#include <population/individual/Genotype.h>

using namespace gram::population::individual;

Genotype::Genotype(std::vector<int> values) : values(values) {
  //
}

int &Genotype::operator[](int index) {
  return values[index];
}

bool Genotype::operator==(const Genotype &genotype) const {
  return values == genotype.values;
}

bool Genotype::operator!=(const Genotype &genotype) const {
  return !operator==(genotype);
}

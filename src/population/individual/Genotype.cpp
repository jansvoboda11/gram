#include <population/individual/Genotype.h>

using namespace gram::population::individual;

Genotype::Genotype(std::vector<int> values) : values(values) {
  //
}

unsigned long Genotype::size() {
  return values.size();
}

std::vector<int> Genotype::genes() {
  return values;
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

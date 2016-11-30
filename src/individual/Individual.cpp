#include <gram/individual/Individual.h>

using namespace gram::grammar;
using namespace gram::individual;

Individual::Individual(Genotype genotype) : genotype(genotype), phenotype() {
  //
}

bool Individual::operator==(const Individual &individual) const {
  return genotype == individual.genotype;
}

bool Individual::operator!=(const Individual &individual) const {
  return !operator==(individual);
}

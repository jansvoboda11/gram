#include <gram/population/individual/Individual.h>

using namespace gram::language::grammar;
using namespace gram::population::individual;

Individual::Individual(Genotype genotype) : genotype(genotype), phenotype() {
  //
}

bool Individual::operator==(const Individual &individual) const {
  return genotype == individual.genotype;
}

bool Individual::operator!=(const Individual &individual) const {
  return !operator==(individual);
}

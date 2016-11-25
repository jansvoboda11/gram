#ifndef GRAM_EVOLUTION_MUTATION_OPERATOR
#define GRAM_EVOLUTION_MUTATION_OPERATOR

#include <population/individual/Genotype.h>
#include <util/NumberGenerator.h>

namespace gram {
namespace evolution {
/**
 * Class.
 */
class Mutation {
 public:
  Mutation(gram::util::NumberGenerator &generator);
  gram::population::individual::Genotype apply(gram::population::individual::Genotype genotype);
 private:
  gram::util::NumberGenerator &generator;
};
}
}

#endif // GRAM_EVOLUTION_MUTATION_OPERATOR
